document.addEventListener('DOMContentLoaded', function () {
  if (!window.jQuery || !jQuery.fn.dataTable) return;
  jQuery('table.perf-datatable').each(function () {
    // No scrollY: keep a single table so header/body columns stay aligned.
    // FixedHeader floats the header on page scroll (aligned, cross-browser).
    jQuery(this).DataTable({
      paging: false, info: false, searching: true, ordering: true,
      autoWidth: false, order: [], fixedHeader: true,
      columnDefs: [{ targets: '_all', type: 'num-fmt' }]
    });
  });
});
