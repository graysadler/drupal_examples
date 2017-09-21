<?php
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('List Index'),
  'description' => t('Prints a linked list to list items.'),
  'category' => t('Miscellaneous'),
  'single' => TRUE,
  'content type' => 'list_index',
);

/**
 * Output function for the list index.
 */
function iin_panels_extras_list_index_content_type_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();
  $pane->content = '';
  $node = nid_loader_lite();

  if (isset($node['nid'])) {
    $this_node = node_load($node['nid']);

    $pane->content = '<a id="list-top"></a>
      <div class="question-nav-wrapper">
      <div class="question-nav list-conf-faqs row-fluid">
      <ol class="question-nav-items span5 offset1">';

    // Add auto index functionality
    $wrapper = entity_metadata_wrapper('node', $this_node);
    $index = 1;
    foreach ($wrapper->field_list_collection as $delta => $collection) {
      $item_id = $collection->item_id->value();
      $title = $collection->field_list_item_title->value();

      if ($index == 0) {
        $class = 'class="active"';
      }
      elseif ($index == count($wrapper->field_list_collection)) {
        $class = 'class="last-question"';
      }
      else {
        $class = '';
      }

      $pane->content .= '<li><a id="item-' . $item_id . '-link" ' . $class . ' href="#item-' . $item_id . '">' . $title . "</a></li>\n";
      $index++;
    }
    $pane->content .= '</ol></div></div>';

    return $pane;
  }
}

/**
 * Admin title.
 */
function iin_panels_extras_list_index_content_type_admin_title($subtype, $conf, $context) {
  return t('Linked list index.');
}
