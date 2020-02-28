<?php

/**
 * @file
 * Contains sparklearn_history.views.inc.
 */

/**
 * Implements hook_views_data().
 */
function sparklearn_history_views_data() {
  $data = [];
  // Base data.
  $data['history']['table']['group'] = t('User history');
  $data['history']['table']['base'] = [
    'field' => 'nid',
    'title' => t('History'),
    'help' => t('History table as base table.'),
    'weight' => -10,
  ];

  // History user id field, exposed as a field, sort, filter, and argument.
  $data['history']['uid'] = [
    'title' => t('History uid field'),
    'help' => t('History uid field.'),
    'field' => [
      'id' => 'standard',
    ],
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'string',
    ],
    'argument' => [
      'id' => 'string',
    ],
  ];

  $data['history']['timestamp'] = [
    'title' => t('History timestamp field'),
    'help' => t('History timestamp field.'),
    'field' => [
      'id' => 'standard',
    ],
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'string',
    ],
    'argument' => [
      'id' => 'string',
    ],
  ];

  $data['history']['nid'] = [
    'title' => t('History nid field'),
    'help' => t('History nid field.'),
    'field' => [
      'id' => 'standard',
    ],
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'string',
    ],
    'argument' => [
      'id' => 'string',
    ],
  ];

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function sparklearn_history_views_data_alter(array &$data) {
  $entity_type_manager = \Drupal::entityTypeManager();

  $entity_type = $entity_type_manager->getDefinition('node');
  if ($entity_type->hasHandlerClass('views_data')) {
    $base_table = $entity_type_manager->getHandler('node', 'views_data')->getViewsTableForEntityType($entity_type);
    $data[$base_table]['history_relationship'] = [
      'title' => t('@entity_label history', ['@entity_label' => $entity_type->getLabel()]),
      'help' => t('Limit results to only those nodes which has history records.'),
      'relationship' => [
        'group' => t('History'),
        'label' => t('History records'),
        'base' => 'history',
        'base field' => 'nid',
        'relationship field' => $entity_type->getKey('id'),
        'id' => 'history_relationship',
      ],
    ];
  }
}
