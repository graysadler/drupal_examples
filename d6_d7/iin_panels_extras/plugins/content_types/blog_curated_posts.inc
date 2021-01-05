<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Blog Curated Posts'),
  'description' => t('Displays blog posts manually curated by IIN staff.'),
  'category' => array(t('Blog'), -9),
  'single' => FALSE,
  'content type' => 'blog_curated_posts',
  'edit form' => 'iin_panels_extras_blog_curated_posts_settings_form',
  'js' => array('misc/autocomplete.js'),
    
);

function iin_panels_extras_blog_curated_posts_settings_form($form, &$form_state) {
  $max = 6;
  $conf = $form_state['conf'];
  
  $form['posts']['#tree'] = TRUE;
  
  for ($i = 1; $i <= $max; $i++) {
    $form['posts'][$i]['#type'] = 'fieldset';
    $form['posts'][$i]['#title'] = 'Item ' . $i;
    
    $form['posts'][$i]['node'] = array(
      '#type' => 'textfield',
      '#title' => 'Blog Post',
      '#autocomplete_path' => 'iin-blog/autocomplete',
      '#default_value' => $conf['posts'][$i]['node'] ? $conf['posts'][$i]['node'] : '',
      '#size' => 75,        
      '#description' => t('Enter the name of the blog post to use in this slot.'),
    );
    $form['posts'][$i]['tag'] = array(
        '#type' => 'textfield',
        '#title' => 'Blog Tag',
        '#default_value' => $conf['posts'][$i]['tag'] ? $conf['posts'][$i]['tag'] : '',
        '#size' => 25,
        '#description' => t('If left empty, the first tag selected in the Blog\'s Category field will be used.'),
    );
    
  }
  
  return $form;
}

function iin_panels_extras_blog_curated_posts_settings_form_submit($form, &$form_state) {
  $form_state['conf']['posts'] = $form_state['values']['posts'];
}

/**
 * Output function for the curated blog posts.
 */
function iin_panels_extras_blog_curated_posts_content_type_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();
  $pane->content = '';
  $labels = array();
  $entities = array();
  $posts = $conf['posts'];
  
  foreach ($posts as $key => $post) {
    if (empty($post['node'])) {
      unset($posts[$key]);
    }
  }
  
  if (empty($posts)) {
    for ($i = 1; $i <= 6; $i++) {
      $labels[$i] = variable_get('iin_blog_item_label_' . $i, '');
      if ($entity = variable_get('iin_blog_curated_node_' . $i, '')) {
        $entities[] = $entity['entity_id'];
      }
    }
    
    if (count($entites)) {
      $posts = entity_load('node', $entities);
    } else {
      // Shouldn't make it here but just in case...bail
      return $pane;
    }    
  }
  
  $j = 1;
  $pane->content = '<div id ="blog-curated-post">';
  foreach($posts as $p) {
    if (is_object($p)) {
      $post = $p;
      $label = $labels[$j];
    } else {
      $preg_matches = array();
      $match = preg_match('/\[(\d+)\]/', $p['node'], $preg_matches);
      if (!$match) {
        continue;
      }
      
      if ($match) {
        $nid = $preg_matches[1];
      }    
      if (!$post = node_load($nid)) {
        continue;
      }
      
      $label = $p['tag'] ? $p['tag'] : FALSE;
      if (!$label) {
        $term = taxonomy_term_load($post->field_blog_category['und'][0]['tid']);
        $label = $term->name;
      }      
    }    
    
    $image = (empty($post->field_special_featured_image)) ? $post->field_featured_image['und'][0] : $post->field_special_featured_image['und'][0];
    $mobile_image = image_style_url('blog_mobile_feature', $image['uri']);
    $mobile_image_narrow = image_style_url('blog_mobile_list', $image['uri']);
    $desktop_image = image_style_url('blog_desktop_featured', $image['uri']);
    
    $pane->content .= '<div class="blog-curated-post blog-curated-post-' . $j . '">';
    $pane->content .= '  <div class="blog-curated-label blog-label blog-curated-label-' . $j . '">' . $label .'</div>';
    $pane->content .= '  <div class="blog-curated-image wide">' .
                           l('<picture>
                             <!--[if IE 9]><video style="display: none;"><![endif]-->
                             <source media="(min-width: 1170px)" srcset="' . $desktop_image . '"></source>
                             <source media="(min-width: 768px)" srcset="' . $desktop_image . '"></source>
                             <source media="(min-width: 0px)" srcset="' . $mobile_image . '"></source>
                             <img alt="' . $image['alt'] . '" srcset="' . $mobile_image . '">
                           </picture>', 'node/' . $post->nid, array('html' => TRUE))
                         . '</div>';
    $pane->content .= '  <div class="blog-curated-image narrow">' .
                          l('<picture>
                             <!--[if IE 9]><video style="display: none;"><![endif]-->
                             <source media="(min-width: 0px)" srcset="' . $mobile_image_narrow . '"></source>
                             <img alt="' . $image['alt'] . '" srcset="' . $mobile_image_narrow . '">
                           </picture>', 'node/' . $post->nid, array('html' => TRUE))
                               . '</div>';    
    $pane->content .= '  <div class="blog-title-overlay">';
    $pane->content .= '    <div class="created">' . date('F j, Y', $post->created) . '</div>';
    $pane->content .= '    <div class="title"><h3>' . l($post->title, 'node/' . $post->nid) . '</h3></div>';
    $pane->content .= '    <div class="read-more"><h3>' . l('Read More', 'node/' . $post->nid) . '</h3></div>';
    $pane->content .= '  </div>';
    $pane->content .= '</div>';
    $j++;
  }
  $pane->content .= '</div>';
  return $pane;
}

/**
 * Admin title.
 */
function iin_panels_extras_blog_curated_posts_content_type_admin_title($subtype, $conf, $context) {
  return t('Curated blog posts.');
}
