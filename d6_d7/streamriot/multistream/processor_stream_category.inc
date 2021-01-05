<?php

/**
 * @file
 * Contains SearchApiIgnoreCase.
 */

/**
 * Processor for making searches case-insensitive.
 */
class SearchApiStreamCategory extends SearchApiAbstractProcessor {


  public function preprocessIndexItems(array &$items) {
    $cats = stream_import_get_games();
    foreach ($items as $id => &$item) {
      foreach($item['field_streams:category']['value'] as &$value) {
        $value = $cats[$value];
      }
    }    
  }  
}
