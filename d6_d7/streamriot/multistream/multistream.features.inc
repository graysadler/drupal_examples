<?php
/**
 * @file
 * multistream.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function multistream_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function multistream_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function multistream_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favoriting of multistreams".
  $flags['multistream_favs'] = array(
    'entity_type' => 'node',
    'title' => 'Favoriting of multistreams',
    'global' => 0,
    'types' => array(
      0 => 'multistream',
    ),
    'flag_short' => 'Fav',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unfav',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'teaser' => 'teaser',
      'full' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'multistream',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "User stream favorites".
  $flags['stream_favs'] = array(
    'entity_type' => 'stream',
    'title' => 'User stream favorites',
    'global' => 0,
    'types' => array(
      0 => 'stream',
    ),
    'flag_short' => 'Fav',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unfav',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(),
    'show_as_field' => FALSE,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'multistream',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function multistream_image_default_styles() {
  $styles = array();

  // Exported image style: stream_thumb.
  $styles['stream_thumb'] = array(
    'name' => 'stream_thumb',
    'label' => 'Stream Thumb',
    'effects' => array(
      13 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 66,
          'height' => 46,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function multistream_node_info() {
  $items = array(
    'multistream' => array(
      'name' => t('Multistream'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Edit Multi-Stream Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function multistream_default_search_api_index() {
  $items = array();
  $items['multistreams'] = entity_import('search_api_index', '{
    "name" : "Multistreams Search Index",
    "machine_name" : "multistreams",
    "description" : null,
    "server" : "search_api_db",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_streams:category" : { "type" : "list\\u003Ctext\\u003E", "boost" : "2.0" },
        "field_streams:channel" : { "type" : "list\\u003Ctext\\u003E" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "3.0" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "default" : "0", "bundles" : { "multistream" : "multistream" } }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "-49", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "-48", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-46", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "-45", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "-44", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "-43", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_streams:channel" : true,
              "field_streams:category" : true
            }
          }
        },
        "multistream_stream_category" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_streams:channel" : true,
              "field_streams:category" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_streams:channel" : true,
              "field_streams:category" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_streams:channel" : true,
              "field_streams:category" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_streams:channel" : true,
              "field_streams:category" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['streams'] = entity_import('search_api_index', '{
    "name" : "Streams Search Index",
    "machine_name" : "streams",
    "description" : null,
    "server" : "search_api_db",
    "item_type" : "stream",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "200",
      "fields" : {
        "category" : { "type" : "text", "boost" : "3.0" },
        "channel" : { "type" : "text" },
        "is_live" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "viewers" : { "type" : "integer" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : false } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "channel" : true, "category" : true } }
        },
        "multistream_stream_category" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "channel" : true, "category" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "channel" : true, "category" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "channel" : true, "category" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "channel" : true, "category" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function multistream_default_search_api_server() {
  $items = array();
  $items['search_api_db'] = entity_import('search_api_server', '{
    "name" : "Search API DB",
    "machine_name" : "search_api_db",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "4",
      "partial_matches" : 1,
      "autocomplete" : { "suggest_suffix" : 1, "suggest_words" : 0 },
      "indexes" : {
        "multistreams" : {
          "title" : {
            "table" : "search_api_db_multistreams_text",
            "type" : "text",
            "boost" : "3.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_multistreams",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_streams:channel" : {
            "table" : "search_api_db_multistreams_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_streams:category" : {
            "table" : "search_api_db_multistreams_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "2.0"
          }
        },
        "streams" : {
          "channel" : {
            "table" : "search_api_db_streams_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "category" : {
            "table" : "search_api_db_streams_text",
            "type" : "text",
            "boost" : "3.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_streams",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "viewers" : {
            "table" : "search_api_db_streams",
            "column" : "viewers",
            "type" : "integer",
            "boost" : "1.0"
          },
          "is_live" : {
            "table" : "search_api_db_streams",
            "column" : "is_live",
            "type" : "integer",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
