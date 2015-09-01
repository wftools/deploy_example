# Deploy Example

This module includes everything you need to start using the [deploy module](https://drupal.org/project/deploy) with standard Drupal components.

Includes the following sub-modules:

* Deploy Example Plan Next: Push to next deployment plan (Not used for Deployment Tools)
* Deploy Example Services: Provides a magic services endpoint configuration that enables all entities for deploy.

## Example $conf variables in settings.php

```
// This is the username in the target environment. This should be configured to be user 1 to avoid permissions issues.
$conf['deploy_example_next_user'] = 'my-site-admin';

// Only set this value if you don't use drush to set the password on a per deployment basis.
$conf['deploy_example_next_pass'] = 'password';

// Set destination services endpoint where we deploy entities.
$conf['deploy_example_next_url'] = 'https://prod.example.com/deploy';

// Set this to TRUE to enable debugging on deployments.
$conf['deploy_example_debug'] = FALSE;
```
