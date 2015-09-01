; Drush make file for deploy_example dependencies.

api = 2
core = "7.x"

projects[] = drupal

projects[bean][version] = "1.9"
projects[bean][subdir] = "contrib"

projects[ctools][version] = "1.9"
projects[ctools][subdir] = "contrib"

projects[deploy][download][type] = "git"
projects[deploy][download][url] = "http://git.drupal.org/project/deploy.git"
projects[deploy][download][revision] = "0bdcdf1"
projects[deploy][subdir] = "contrib"

; Remove all entities from a managed deployment plan.
projects[deploy][patch][2499783][url] = "https://www.drupal.org/files/issues/deploy-empty-deploy-plan-2499783-1.patch"
projects[deploy][patch][2499783][md5] = "b4c4e635513ef60c1df29abf73e2fce1"

; Added patch to react to post deploy hook.
projects[deploy][patch][1890408][url] = "https://www.drupal.org/files/issues/deploy-add-post-deploy-hooks.patch"
projects[deploy][patch][1890408][md5] = "f2faef7c1aa426617a3793d4fe77c54d"

projects[diff][version] = "3.2"
projects[diff][subdir] = "contrib"

projects[entity][version] = "1.6"
projects[entity][subdir] = "contrib"

projects[entity_dependency][version] = "1.0-alpha2"
projects[entity_dependency][subdir] = "contrib"

projects[entity_menu_links][version] = "1.0-alpha3"
projects[entity_menu_links][subdir] = "contrib"

projects[libraries][version] = "2.2"
projects[libraries][subdir] = "contrib"

projects[rules][version] = "2.9"
projects[rules][subdir] = "contrib"

projects[services][version] = "3.12"
projects[services][subdir] = "contrib"

projects[services_basic_auth][version] = "1.3"
projects[services_basic_auth][subdir] = "contrib"

projects[stage_file_proxy][version] = "1.7"
projects[stage_file_proxy][subdir] = "contrib"

projects[uuid][download][type] = "git"
projects[uuid][download][url] = "http://git.drupal.org/project/uuid.git"
projects[uuid][download][revision] = "a7bf2db"
projects[uuid][subdir] = "contrib"

projects[uuid_extras][version] = "1.0-alpha1"
projects[uuid_extras][subdir] = "contrib"
