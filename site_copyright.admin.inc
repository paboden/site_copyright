<?php

/**
 * Creates/returns a form to configure the block's variables.
 *
 * @param array $form
 * @param array $form_state
 * @return array
 */
function site_copyright_configure($form, &$form_state) {
  global $language;
  $lang = ($language->language == 'en') ? '' : '_' . $language->language;
  $lang_name = ($language->language == 'en') ? '' : ' - ' . $language->name;

  $form['site_copyright_copyright' . $lang] = array(
    '#type' => 'textfield',
    '#title' => t('Site copyright owner') . $lang_name,
    '#description' => t('The company/organization/person/entity to show as copyright holder.'),
    '#default_value' => variable_get('site_copyright_copyright' . $lang, 'Copyright holder'),
    '#size' => 60,
    '#maxlength' => 120,
    '#required' => TRUE,
  );

  $form['site_copyright_copyright_start'] = array(
    '#type' => 'textfield',
    '#title' => t('Site copyright start date'),
    '#description' => t('The start date for copyright of the content; end date is assumed to be the current year.'),
    '#default_value' => variable_get('site_copyright_copyright_start', ''),
    '#size' => 4,
    '#maxlength' => 4,
    '#required' => FALSE,
  );
  $form['site_copyright_phone' . $lang] = array(
    '#type' => 'textfield',
    '#title' => t('Site phone number') . $lang_name,
    '#description' => t('The phone number of the copyright holder.'),
    '#default_value' => variable_get('site_copyright_phone' . $lang, ''),
    '#size' => 20,
    '#maxlength' => 20,
    '#required' => FALSE,
  );
  $form['site_copyright_address' . $lang] = array(
    '#type' => 'textfield',
    '#title' => t('Site street address') . $lang_name,
    '#description' => t('The street address of the copyright holder.'),
    '#default_value' => variable_get('site_copyright_address' . $lang, ''),
    '#size' => 120,
    '#maxlength' => 120,
    '#required' => FALSE,
  );

  // Use system_settings_form() to automate saving configuration variables.
  return system_settings_form($form);
}