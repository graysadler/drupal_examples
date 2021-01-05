<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Blog Page Opt In'),
  'description' => t('Displays the selected blog opt in.'),
  'category' => t('Blog'),
  'single' => TRUE,
  'content type' => 'blog_page_opt_in',
);

/**
 * Output function for the curated blog posts.
 */
function iin_panels_extras_blog_page_opt_in_content_type_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();
  $pane->content = '';
  $arg1 = arg(1);
  $node = node_load($arg1);

  if (isset($node->field_opt_in['und'][0]['value'])) {
    $optin_node = node_load($node->field_opt_in['und'][0]['value']);
    $node_view = node_view($optin_node);
    $pane->content = drupal_render($node_view);
  }

  return $pane;
}

/**
 * Admin title.
 */
function iin_panels_extras_blog_page_opt_in_content_type_admin_title($subtype, $conf, $context) {
  return t('Blog Opt In.');
}
