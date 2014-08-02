<?php
/**
 * Implements hook_uninstall()
 *
 * Remove variables used.
 */
function sitename_footer_uninstall() {
  variable_del('sitename_footer_copyright');
  variable_del('sitename_footer_copyright_start');
  variable_del('sitename_footer_phone');
  variable_del('sitename_footer_address');
}