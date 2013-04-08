<?php
// $Id$

// Copyright (c) 2010 KontextWork
// Author: Eugen Mayer
class view_select_plugin_style_views_select extends views_plugin_style_table {
  function option_definition() {
    $options = parent::option_definition();

    $options['jscallback'] = array('default' => array());
    $options['value_col'] = array('default' => '');
    return $options;
  }
  
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    $form['jscallback'] = array( 
      '#type' => 'textfield',
      '#title' => t('Your JS callback'),
      '#default_value' => $this->options['jscallback'],
    );
    $options = $this->display->handler->get_field_labels();

    $form['value_col'] = array( 
      '#type' => 'select',
      '#title' => t('Value field'),
      '#options' => $options,
      '#default_value' => $this->options['value_col'],
      '#description' => t('Select the column which will be submitted as value (first argument) to the js callback function'),
    );
  }

  function render() {
    $m = drupal_get_path('module','views_select');
    drupal_add_js("$m/js/jquery.table_select.js");
    drupal_add_js("$m/js/views_select.js");
    drupal_add_css("$m/css/views_select.css");


    $settings = array();
    $settings['view_name'] = $this->view->name;
    $settings['table_sel'] = ".view-id-{$settings['view_name']} table.views-table";
    $col = str_replace('_','-',$this->options['value_col']);
    $settings['value_col_sel'] = "td.views-field-$col";
    $settings['callback'] = "{$this->options['jscallback']}";

    drupal_add_js(
      array(
        'views_select' => array(
          $settings['view_name'] => $settings,
        ),
      ),
      'setting'
    );
    return parent::render();
  }
}