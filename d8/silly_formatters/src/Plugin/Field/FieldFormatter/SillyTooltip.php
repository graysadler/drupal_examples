<?php

namespace Drupal\silly_formatters\Plugin\Field\FieldFormatter;

use Drupal\Core\Field\FormatterBase;
use Drupal\Core\Field\FieldItemListInterface;
use Drupal\Core\Field\FieldItemInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 * Plugin implementation of the 'silly_tooltip' formatter.
 *
 * @FieldFormatter(
 *   id = "silly_tooltip",
 *   weight = 10,
 *   label = @Translation("Tooltip"),
 *   field_types = {"string", "string_long", "text", "text_long", "text_with_summary"}
 * )
 */
class SillyTooltip extends FormatterBase {
  
  /**
   * {@inheritdoc}
   */
  public function viewElements(FieldItemListInterface $items, $langcode) {
    $element = [];
    
    foreach ($items as $delta => $item) {
      $element[$delta] = $this->viewElement($item, $langcode);
    }
    
    return $element;
  }
  
  /**
   * Adds tooltip library and calls our silly template
   * @param \Drupal\core\field\FieldItemInterface $item
   *   The field item.
   * @param string $langcode
   *   The language that should be used to render the field.
   *
   * @return array
   *   A renderable array.
   */
  protected function viewElement(FieldItemInterface $item, $langcode) {
    $element = [
      '#theme' => 'silly_tooltip',
      '#item' => $item,
      '#attached' => [
        'library' => [
          'silly_formatters/silly_tooltip',
        ],
      ],
    ];
    
    return $element;
  }
  
}