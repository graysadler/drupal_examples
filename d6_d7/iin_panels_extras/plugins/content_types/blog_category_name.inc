<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Blog Category Name'),
  'description' => t('Shows the name of the category currently being viewed.'),
  'category' => t('Blog'),
  'single' => TRUE,
  'content type' => 'blog_category_name',
);

/**
 * Output function for the curated blog posts.
 */
function iin_panels_extras_blog_category_name_content_type_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();
  $pane->content = '';

  $arg2 = arg(2);

  $term = taxonomy_term_load($arg2);

  $pane->content .= '<h3><strong>ALL POSTS TAGGED:</strong> <span class="blog-category-name">' . strtoupper($term->name) . '</span></h3>';

  return $pane;
}

/**
 * Admin title.
 */
function iin_panels_extras_blog_category_name_content_type_admin_title($subtype, $conf, $context) {
  return t('Blog Category Name.');
}
