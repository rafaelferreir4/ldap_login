<?php
/**
 * @file
 * Admin-only functionality for LDAP.
 */

/*
 * Admin configuration for LDAP connection.
 */
function ldap_login_settings_form($form, &$form_state) {
  $form['ldap_login_general'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Connection settings'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
  );

  $form['ldap_login_general']['ldap_login_base_dn'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Base DN'),
    '#default_value' => variable_get('ldap_login_base_dn', ''),
    '#description'   => t('Example: DC=RD,DC=Local'),
    '#maxlength'     => NULL,
  );

  $form['ldap_login_general']['ldap_login_domain_controllers'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Domain controllers'),
    '#default_value' => variable_get('ldap_login_domain_controllers', ''),
    '#maxlength'     => NULL,
  );

  $form['ldap_login_general']['ldap_login_account_suffix'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Account suffix'),
    '#default_value' => variable_get('ldap_login_account_suffix', ''),
    '#maxlength'     => NULL,
  );

  $form['ldap_login_general']['ldap_login_port'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Port'),
    '#default_value' => variable_get('ldap_login_port', '389'),
    '#maxlength'     => NULL,
  );

  $form['ldap_login_general']['ldap_login_real_primarygroup'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Real primary group'),
    '#default_value' => variable_get('ldap_login_real_primarygroup', TRUE),
  );

  $form['ldap_login_general']['ldap_login_use_ssl'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Use SSL'),
    '#default_value' => variable_get('ldap_login_use_ssl', FALSE),
  );

  $form['ldap_login_general']['ldap_login_use_tls'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Use TLS'),
    '#default_value' => variable_get('ldap_login_use_tls', FALSE),
  );

  $form['ldap_login_general']['ldap_login_recursive_groups'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Recursive groups'),
    '#default_value' => variable_get('ldap_login_recursive_groups', TRUE),
  );

  $form['ldap_login_general']['ldap_login_sso'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('SSO'),
    '#default_value' => variable_get('ldap_login_sso', FALSE),
  );

  $form['ldap_login_auth'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Authentication'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
  );

  $form['ldap_login_auth']['ldap_login_admin_user'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Admin user'),
    '#default_value' => variable_get('ldap_login_admin_user', ''),
    '#maxlength'     => NULL,
  );

  $form['ldap_login_auth']['ldap_login_admin_password'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Password'),
    '#default_value' => variable_get('ldap_login_admin_password', ''),
    '#maxlength'     => NULL,
  );

  $form['ldap_login_roles'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Role mapping'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
  );

  $form['ldap_login_roles']['ldap_login_user_roles_description'] = array(
    '#markup' => t('Map the Drupal roles with the AD ones. i.e.: Drupal-Webmaster. Separate them with a coma.'),
  );

  foreach (user_roles() as $rid => $role) {
    $form['ldap_login_roles']['ldap_login_role_mapping_' . $rid] = array(
      '#type'          => 'textfield',
      '#title'         => t('Map role "@role"', array('@role' => $role)),
      '#default_value' => variable_get('ldap_login_role_mapping_' . $rid, ''),
      '#maxlength'     => NULL,
    );
  }

  return system_settings_form($form);
}
