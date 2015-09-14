<?php
/**
 * @file
 * sevone_persona.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function sevone_persona_taxonomy_default_vocabularies() {
  $taxonomy = array(
    'persona' => array(
      'name' => 'Persona',
      'machine_name' => 'persona',
      'description' => 'Used to track the type of site user',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );

  features_alter_code('taxonomy', $taxonomy);

  return $taxonomy;
}
