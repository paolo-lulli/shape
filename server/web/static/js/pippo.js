pippo = new Object()
pippo.init = function(baseurl){
        this.baseurl=baseurl;
}
pippo.insert = function(baseurl, landing_page){
        console.log("baseurl:"+baseurl);
        $( document ).ready(function() {
        console.log(":READY:");
                $("#pippo-insert").submit(function(event) {
                /* Stop form from submitting normally */
                event.preventDefault();

		var f_uno              = $("#pippo-insert-fields").find('#uno').val();
		var f_due              = $("#pippo-insert-fields").find('#due').val();
		var f_tre              = $("#pippo-insert-fields").find('#tre').val();
	$.ajax({
		 url: baseurl+"/xhr/pippo.php?method=INSERT&uno="+f_uno+"&due="+f_due+"&tre="+f_tre+"",
			dataType: "jsonp",
                        jsonp : "callback",
                        jsonpCallback: "xhr_pippo_save",
                        type: "get",
                        data: null,
                        success: function(data){
                                console.log("success:"+data);
                        },
                        error:function(){
                                console.log("failure");
                        }
                });
                });
        });
}
pippo.update = function(baseurl, id_pippo, landing_page){
        console.log("baseurl:"+baseurl);
        $( document ).ready(function() {
        console.log(":READY:");
                $("#pippo-update").submit(function(event) {
                /* Stop form from submitting normally */
                event.preventDefault();

		var f_uno              = $("#pippo-update").find('#uno').val();
		var f_due              = $("#pippo-update").find('#due').val();
		var f_tre              = $("#pippo-update").find('#tre').val();
	$.ajax({
		 url: baseurl+"/xhr/pippo.php?method=UPDATE&id_pippo="+id_pippo+"&uno="+f_uno+"&due="+f_due+"&tre="+f_tre+"",
			dataType: "jsonp",
                        jsonp : "callback",
                        jsonpCallback: "xhr_pippo_update",
                        type: "get",
                        data: null,
                        success: function(data){
                                console.log("success:"+data);
                        },
                        error:function(){
                                console.log("failure");
                        }
                });
                });
        });
}
pippo.list = function(baseurl, landing_page){
        console.log("baseurl:"+baseurl);
        $( document ).ready(function() {
        console.log("LIST:READY:pippo.list");
        console.log("LIST:BOUND:");

                $.ajax({
                        url: baseurl+"/xhr/pippo.php?method=LIST",
                        dataType: "jsonp",
                        jsonp : "callback",
                        jsonpCallback: "xhr_pippo_list",
                        type: "get",
                        data: null,
                        success: function(data){
                                console.log("success:"+data);
                        },
                        error:function(){
                                console.log("failure");
                        }
                });
                });
}
pippo.search = function(baseurl, landing_page){
        console.log("baseurl:"+baseurl);
        $( document ).ready(function() {
        console.log(":READY:");
                $("#pippo-search").submit(function(event) {
                /* Stop form from submitting normally */
                event.preventDefault();

		var f_due              = $("#pippo-search").find('#due').val();
		var f_tre              = $("#pippo-search").find('#tre').val();
	$.ajax({
		 url: baseurl+"/xhr/pippo.php?method=SEARCH&due="+f_due+"&tre="+f_tre+"",
			dataType: "jsonp",
                        jsonp : "callback",
                        jsonpCallback: "xhr_pippo_search",
                        type: "get",
                        data: null,
                        success: function(data){
                                console.log("success:"+data);
                        },
                        error:function(){
                                console.log("failure");
                        }
                });
                });
        });
}
pippo.retrieve = function(baseurl, landing_page){
        console.log("baseurl:"+baseurl);
        $( document ).ready(function() {
        console.log(":READY:");
                $("#pippo-search").submit(function(event) {
                /* Stop form from submitting normally */
                event.preventDefault();

		var f_due              = $("#pippo").find('#due').val();
		var f_tre              = $("#pippo").find('#tre').val();
	$.ajax({
		 url: baseurl+"/xhr/pippo.php?method=SEARCH&due="+f_due+"&tre="+f_tre+"",
			dataType: "jsonp",
                        jsonp : "callback",
                        jsonpCallback: "xhr_pippo_retrieve",
                        type: "get",
                        data: null,
                        success: function(data){
                                console.log("success:"+data);
                        },
                        error:function(){
                                console.log("failure");
                        }
                });
                });
        });
}
pippo.show = function(baseurl, id_pippo){
        console.log("baseurl:"+baseurl);
        $( document ).ready(function() {
        console.log(":READY:pippo.show");
                console.log("id_pippo="+id_pippo);
                $.ajax({
                        url: baseurl+"/xhr/pippo.php?method=SHOW&id_pippo="+id_pippo,
                        dataType: "jsonp",
                        jsonp : "callback",
                        jsonpCallback: "xhr_pippo_show",
                        type: "get",
                        data: null,
                        success: function(data){
                                console.log("success:"+data);
                        },
                        error:function(){
                                console.log("failure");
                        }
                });
        });
}
pippo.del = function(baseurl, id_pippo){
        console.log("baseurl:"+baseurl);
        $( document ).ready(function() {
        console.log(":READY:pippo.del");
                console.log("id_pippo="+id_pippo);
                $.ajax({
                        url: baseurl+"/xhr/pippo.php?method=DELETE&id_pippo="+id_pippo,
                        dataType: "jsonp",
                        jsonp : "callback",
                        jsonpCallback: "xhr_pippo_delete",
                        type: "get",
                        data: null,
                        success: function(data){
                                console.log("success:"+data);
                        },
                        error:function(){
                                console.log("failure");
                        }
                });
        });
}
