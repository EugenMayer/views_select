// $Id$

// Copyright (c) 2010 KontextWork
// Author: Eugen Mayer

(function($) {
  $.fn.table_select = function(options) {
    return this.each( function(){
      // **************** Init *****************/
      var $table = $(this);
      var value_col_sel = options.value_col_sel;
      var callback = options.callback;
      bind_rows($table);
 
      function bind_rows($table) {
        $table.find('tr').bind('click', row_clicked);
      }
      
      function row_clicked(event) {
        var value = $(this).find(value_col_sel).html();
        window[callback](value);
      }
    }
    );
  }
})(jQuery);