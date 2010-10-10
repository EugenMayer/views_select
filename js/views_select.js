Drupal.behaviors.views_select = function (context) {
  var settings =  Drupal.settings.views_select;
  $.each(
    settings,
    function(view_name,view_settings) {
      var options = {
        value_col_sel : view_settings.value_col_sel,
        callback : view_settings.callback
      }
      $(view_settings.table_sel).table_select(options);
    }
  );
}