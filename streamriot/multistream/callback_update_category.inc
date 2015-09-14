<?php

/**
 * @file
 * Contains SearchApiAlterAddUrl.
 */

/**
 * Search API data alteration callback that adds an URL field for all items.
 */
class SearchApiAlterUpdateCategory extends SearchApiAbstractAlterCallback {

  public function alterItems(array &$items) {
    //$test = 'test';
    $cats = stream_import_get_games();
    foreach ($items as $id => &$item) {
      foreach($field_streams as &$stream) {
        $stream['category'] = $cats[$stream['category']];
      }
    }
    
    $test = 'test';    
  }

  /*
  public function propertyInfo() {
    return array(
      'search_api_url' => array(
        'label' => t('URI'),
        'description' => t('An URI where the item can be accessed.'),
        'type' => 'uri',
      ),
    );
  }
  */

}
