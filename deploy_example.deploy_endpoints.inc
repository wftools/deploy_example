<?php
/**
 * @file
 * deploy_example.deploy_endpoints.inc
 */

/**
 * Implements hook_deploy_endpoints_default().
 */
function deploy_example_deploy_endpoints_default() {
  $export = array();

  $endpoint = new DeployEndpoint();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 1;
  $endpoint->name = 'next';
  $endpoint->title = 'Next';
  $endpoint->description = 'Generic endpoint that will be overwritten by config array variables.';
  $endpoint->debug = variable_get('deploy_example_debug', 0);
  $endpoint->authenticator_plugin = 'DeployAuthenticatorSession';
  $endpoint->authenticator_config = array(
    'username' => variable_get('deploy_example_next_user'),
    'password' => variable_get('deploy_example_next_pass'),
  );
  $endpoint->service_plugin = 'DeployServiceRestJSON';
  $endpoint->service_config = array(
    'url' => variable_get('deploy_example_next_url'),
  );
  $export['next'] = $endpoint;

  return $export;
}
