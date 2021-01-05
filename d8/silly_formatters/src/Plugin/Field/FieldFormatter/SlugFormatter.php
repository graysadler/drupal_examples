<?php

namespace Drupal\silly_formatters\Plugin\Field\FieldFormatter;

use Drupal\Core\Field\FormatterBase;
use Drupal\Core\Field\FieldItemListInterface;
use Drupal\Core\Field\FieldItemInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 * Plugin implementation of the 'silly_slug' formatter.
 *
 * @FieldFormatter(
 *   id = "silly_slug",
 *   weight = 10,
 *   label = @Translation("Slug"),
 *   field_types = {"string", "string_long", "text", "text_long", "text_with_summary"}
 * )
 */
class SlugFormatter extends FormatterBase {
  /**
   * {@inheritdoc}
   */
  public static function defaultSettings() {
    return [
        'separator' => '-',
    ] + parent::defaultSettings();
  }
  
  /**
   * {@inheritdoc}
   */
  public function settingsForm(array $form, FormStateInterface $form_state) {
    $form = parent::settingsForm($form, $form_state);
    
    $form['separator'] = [
        '#title' => $this->t('Slug separator'),
        '#description' => $this->t('The separator to use in the slug.'),
        '#type' => 'textfield',
        '#default_value' => $this->getSetting('separator'),
    ];
    
    return $form;
  }
  
  /**
   * {@inheritdoc}
   */
  public function settingsSummary() {
    $summary = [];
    $settings = $this->getSettings();
    $summary[] = $this->t('Separator: ') . $settings['separator'];
    
    return $summary;
  }

  /**
   * {@inheritdoc}
   */
  public function viewElements(FieldItemListInterface $items, $langcode) {
    $element = [];

    foreach ($items as $delta => $item) {
      // Render each element as markup.
      $element[$delta] = $this->viewElement($item, $langcode);
    }

    return $element;
  }
  
  /**
   * Converts a textfield to a slug
   * @param \Drupal\core\field\FieldItemInterface $item
   *   The field item.
   * @param string $langcode
   *   The language that should be used to render the field.
   *
   * @return array
   *   A renderable array.
   */
  protected function viewElement(FieldItemInterface $item, $langcode) {
    $string = $item->value;

    $slug = \Drupal::service('silly_formatters.slugify'); 
    $slugged = $slug->slugify($string, $this->getSetting('separator'));
    
    $element = [
      '#markup' => $slugged,
    ];
    
    return $element;
  }

}