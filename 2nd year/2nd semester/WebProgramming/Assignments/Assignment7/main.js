$(document).ready(function() {
    //function addRowHandlers() {
        var table = document.getElementById("gbentries-table");
        var rows = table.getElementsByTagName("tr");
        for (i = 1; i < rows.length; i++) {
            var row = table.rows[i];
            row.onclick = function(myrow){
                              return function() { 
                                 var cell = myrow.getElementsByTagName("td")[0];
                                 var id = cell.innerHTML;
                                 //alert("stuff: "+ myrow.getElementsByTagName("td")[1].innerHTML);
                                 //alert("id:" + id);

                                 document.getElementById("id-input").value = myrow.getElementsByTagName("td")[0].innerHTML;
                                 document.getElementById("email-input").value = myrow.getElementsByTagName("td")[1].innerHTML;
                                 document.getElementById("title-input").value = myrow.getElementsByTagName("td")[2].innerHTML;
                                 document.getElementById("comment-input").value = myrow.getElementsByTagName("td")[3].innerHTML;
                          };
                      }(row);
        }
    //}

    /*
    //function addSelectHandlers() {
        var authorsselect = document.getElementById("authors-select");
        var rows = authorsselect.getElementsByTagName("option");
        for (i = 1; i < rows.length; i++) {
            var row = authorsselect.rows[i];
            row.onclick = function(myrow){
                              return function() { 
                                 var cell = myrow.getElementsByTagName("option");
                                 var id = cell.innerHTML;
                                 alert("id:" + id);
                          };
                      }(row);
        }
    //}
    */
});

function authorsSelectChanged(event) {
    //alert(event.target.value);
    // probably not gonna use this anymore
}