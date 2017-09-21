<?php
/**
 * @file
 * Displays a clean-markup region.
 *
 * Available variables:
 * - $is_region_wrapper: TRUE if a region wrapper should be output, FALSE if it
 *   should not.
 * - $region_wrapper: The element to wrap the region in.
 * - $region_classes: Any classes to apply to the region wrapper.
 * - $display_inner_div: TRUE if an inner div should be output, FALSE if it
 *   should not.
 * - $panes: The HTML of the different panes contained in this region. This file
 *   will not be called if the region is empty!
 *
 * @see template_preprocess_clean_markup_panels_clean_region()
 *
 * @ingroup themeable
 */
?>
<?php if (!empty($panes)):?>
<div class="custom-region">
<?php print $panes; ?>
</div>
<?php endif; ?>