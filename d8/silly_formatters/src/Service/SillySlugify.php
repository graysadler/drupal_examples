<?php

namespace Drupal\silly_formatters\Service;

use Cocur\Slugify\Slugify;
use Drupal\Core\DependencyInjection\ServiceProviderBase;

class SillySlugify extends ServiceProviderBase {
  protected $slug;
  
  /**
   * Constructs a new Slugify object.
   */
  public function __construct() {
    $this->slug = new Slugify();  
  }
  
  public function slugify($text, $separator) {
    return $this->slug->slugify($text, $separator);
  }
}