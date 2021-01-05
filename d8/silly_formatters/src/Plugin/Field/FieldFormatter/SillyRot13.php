<?php

namespace Drupal\silly_formatters\Plugin\Field\FieldFormatter;

use Drupal\Core\Field\FormatterBase;
use Drupal\Core\Field\FieldItemListInterface;
use Drupal\Core\Field\FieldItemInterface;

/**
 * Plugin implementation of the 'silly_rot13' formatter.
 *
 * @FieldFormatter(
 *   id = "silly_rot13",
 *   weight = 10,
 *   label = @Translation("ROT13"),
 *   field_types = {"string", "string_long", "text", "text_long", "text_with_summary"}
 * )
 */
class SillyRot13 extends FormatterBase {

  /**
   * {@inheritdoc}
   */
  public function settingsSummary() {
    $summary = [];
    $summary[] = $this->t('Displays text in ROT13 encoding.');
    return $summary;
  }

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
   * Converts a textfield to Rot13
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
    $rot13 = '';
    
    // Thanks to stackoverflow we don't need str_rot13()
    for ($i = 0, $j = strlen($string); $i < $j; $i++)
    {
      // Get the ASCII character for the current character
      $char = ord($string[$i]);
      
      // If that character is in the range A-Z or a-z, add 13 to its ASCII value
      if( ($char >= 65  && $char <= 90) || ($char >= 97 && $char <= 122))
      {
        $char += 13;
        
        // If we should have wrapped around the alphabet, subtract 26
        if( $char > 122 || ( $char > 90 && ord( $string[$i]) <= 90))
        {
          $char -= 26;
        }
      }
      $rot13 .= chr( $char);
    }
    
    
    $element = [
      '#markup' => $rot13,
    ];
    
    return $element;
  }
}