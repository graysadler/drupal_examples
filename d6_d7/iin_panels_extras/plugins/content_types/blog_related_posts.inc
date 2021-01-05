<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Blog Page Related Posts'),
  'description' => t('Shows related posts based on the current post\'s selected category.'),
  'category' => t('Blog'),
  'single' => TRUE,
  'content type' => 'blog_related_posts',
);

/**
 * Output function for the curated blog posts.
 */
function iin_panels_extras_blog_related_posts_content_type_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();
  $pane->content = '';
  $arg1 = arg(1);
  $node = node_load($arg1);
  $category = $node->field_blog_category['und'][0]['tid'];

  if (!empty($category)) {
    $terms = db_query('SELECT nid FROM {taxonomy_index} WHERE tid = :tid AND nid != :nid ORDER BY created DESC LIMIT 3',
      array(':tid' => $category, ':nid' => $node->nid));
    $pane->content .= '  <h3 class="blog-related-posts-title">Related Posts:</h3>';

    foreach ($terms as $term) {
      $term_node = node_load($term->nid);
      $image = (empty($term_node->field_special_featured_image)) ? $term_node->field_featured_image['und'][0] : $term_node->field_special_featured_image['und'][0];
      $image_style = image_style_url('blog_mobile_list', $image['uri']);

      $pane->content .= '  <div class="blog-related-posts-wrapper">';
      $pane->content .= '  <div class="blog-related-posts-image">' .
                             l('<img alt="' . $image['alt'] . '" src="' . $image_style . '">',
                             'node/' . $term_node->nid, array('html' => TRUE))
                        . '</div>';
      $pane->content .= '  <div class="blog-related-posts-content">
                             ' . l('<p class="blog-related-posts-title">' . $term_node->title . '</p>', 'node/' . $term_node->nid, array('html' => TRUE)) . '
                           </div>';
      $pane->content .= '</div>';
    }
  }

  return $pane;
}

/**
 * Admin title.
 */
function iin_panels_extras_blog_related_posts_content_type_admin_title($subtype, $conf, $context) {
  return t('Blog Related Posts.');
}

