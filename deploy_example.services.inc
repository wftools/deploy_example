<?php
/**
 * @file
 * deploy_example.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function deploy_example_default_services_endpoint() {
  $export = array();

  /* Deploy */
  $enabled_resources = array();
  $available_resources = services_get_resources();
  foreach ($available_resources as $type => $data) {
    if (in_array($type, array('system', 'user'))) {
      continue;
    }

    $enabled_resources[$type] = array('operations' => array());
    foreach (array_keys($data['operations']) as $operation) {
      switch ($operation) {
        case 'create':
        case 'retrieve':
        case 'update':
          $enabled_resources[$type]['operations'][$operation] = array('enabled' => TRUE);
          break;
      }
    }
  }

  $enabled_resources['user'] = array(
      'actions' => array(
        'login' => array(
          'enabled' => '1',
          ),
        'logout' => array(
          'enabled' => '1',
          ),
        'token' => array(
          'enabled' => '1',
          ),
        ),
      );

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE;
  $endpoint->api_version = 3;
  $endpoint->name = 'deploy';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'deploy';
  $endpoint->authentication = array(
    'services' => 'services',
  );
  $endpoint->server_settings = array(
    'formatters' => array(
      'json' => TRUE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
    ),
  );
  $endpoint->resources = $enabled_resources;
  $endpoint->debug = variable_get('deploy_example_debug', 0);
  $export['deploy'] = $endpoint;

  /* Entity Diff */
  $endpoint = new stdClass();
  $endpoint->disabled = FALSE;
  $endpoint->api_version = 3;
  $endpoint->name = 'entity_diff';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'entity-diff';
  $endpoint->authentication = array(
    'services_basic_auth' => 'services_basic_auth',
  );
  $endpoint->server_settings = array(
    'formatters' => array(
      'json' => TRUE,
      'bencode' => FALSE,
      'jsonp' => FALSE,
      'php' => FALSE,
      'xml' => FALSE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/vnd.php.serialized' => FALSE,
      'application/x-www-form-urlencoded' => FALSE,
      'application/xml' => FALSE,
      'multipart/form-data' => FALSE,
      'text/xml' => FALSE,
    ),
  );
  $endpoint->resources = array(
    'deploy' => array(
      'targeted_actions' => array(
        'diff' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = variable_get('deploy_example_debug', 0);
  $export['entity_diff'] = $endpoint;

  return $export;
}
