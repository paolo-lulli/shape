shape = new Object()
shape.init = function(baseurl){
	this.baseurl=baseurl;
}


//REQUIRES JQm for $.mobile.changePage(landing_page);

/*
 *  Links a form username/password to a backend URL
 */
shape.login = function(baseurl, landing_page){
	console.log("baseurl:"+baseurl);
	$( document ).ready(function() {
		$("#login_form").submit(function(event) {
    			/* Stop form from submitting normally */
    			event.preventDefault();
    			$("#result").html('');
    			var f_username 	= $("#login_form").find('.username').val();
    			var f_password 	= $("#login_form").find('.password').val();
    			var f_role 	= $("#login_form").find('.role').val();
    			console.log("username:"+f_username+", password:"+f_password+",role:"+f_role);
			//
    			$.ajax({
        			url: baseurl+"/xhr-auth/login.php?username="+f_username+"&password="+f_password,
				dataType: "jsonp",
    				jsonp : "callback",
    				jsonpCallback: "xhr_login",
        			type: "get",
        			data: null,
        			success: function(data){
            				console.log("success:"+data);
            				$("#result").html('Submitted successfully');
	    				//document.location=landing_page;
            				//$("#result").html(data);
        			},
        			error:function(){
            				console.log("failure");
            				//$("#result").html('There is error while submit');
            				$("#result").html('Wrong Username/Password');
        			}
    			});
			//
    			$.ajax({
        			url: baseurl+"/xhr-auth/selectRole.php?role="+f_role,
				dataType: "jsonp",
    				jsonp : "callback",
    				jsonpCallback: "xhr_selectRole",
        			type: "get",
        			data: null,
        			success: function(data){
            				console.log("success:"+data);
            				$("#result").html('Submitted successfully');
	    				document.location=landing_page;
	    				//PPPPPPP$.mobile.changePage(landing_page);
            				//$("#result").html(data);
        			},
        			error:function(){
            				console.log("failure");
            				//$("#result").html('There is error while submit');
            				//$("#result").html('Wrong ROLE');
            				$("#result").html('Wrong Username/Password');
        			}
    			});
			//

		});
	});
}
/*
 *  Links a form username/password to a backend URL
 */
shape.simpleLogin = function(baseurl, landing_page){
	console.log("baseurl:"+baseurl);
	$( document ).ready(function() {
		$("#simple_login_form").submit(function(event) {
    		/* Stop form from submitting normally */
    		event.preventDefault();
    		$("#result").html('');
    		var f_username = $("#simple_login_form").find('.username').val();
    		var f_password = $("#simple_login_form").find('.password').val();
    		console.log("username:"+f_username+", password:"+f_password);
    		$.ajax({
        		url: baseurl+"/xhr-auth/login.php?username="+f_username+"&password="+f_password,
			dataType: "jsonp",
    			jsonp : "callback",
    			jsonpCallback: "xhr_login",
        		type: "get",
        		data: null,
        		success: function(data){
            			console.log("success:"+data);
            			$("#result").html('Submitted successfully');
        		},
        		error:function(){
            			console.log("failure");
            			$("#result").html('There is error while submit');
        		}
    		});
		});
	});
}

shape.registerUser = function(baseurl, landing_page){
        console.log("baseurl:"+baseurl);
        $( document ).ready(function() {
                $("#shape-registration_form").submit(function(event) {
                /* Stop form from submitting normally */
                event.preventDefault();
                $("#result").html('');
                var f_firstname = $("#shape-registration_form").find('.firstname').val();
                var f_lastname 	= $("#shape-registration_form").find('.lastname').val();
                var f_username 	= $("#shape-registration_form").find('.username').val();
                var f_email 	= $("#shape-registration_form").find('.email').val();
                var f_password 	= $("#shape-registration_form").find('.password').val();
                var f_role 	= $("#shape-registration_form").find('.role').val();
                console.log("username:"+f_username+", password:"+f_password+",username:"+f_username+",password:"+f_password+",email:"+f_email);
                $.ajax({
                        url: baseurl+"/xhr/register.php?username="+f_username+"&password="+f_password+"&firstname="+f_firstname+"&lastname="+f_lastname+"&email="+f_email+"&role="+f_role,
                        dataType: "jsonp",
                        jsonp : "callback",
                        jsonpCallback: "xhr_register",
                        type: "get",
                        data: null,
                        success: function(data){
                                console.log("success:"+data);
	    			//document.location=landing_page;
				 $.mobile.changePage(landing_page); 
                                //$("#result").html('Submitted successfully');
                                //document.location="app.html#two";
                                //document.location=landing_page;
                //$("#result").html(data);
                        },
                        error:function(){
                                console.log("failure");
                                //$("#result").html('There is error while submit');
                        }
                });
                });
        });
}
/*
 *  Links a form username/password to a backend URL
 */
shape.selectRole = function(baseurl, landing_page){
	console.log("baseurl:"+baseurl);
	$( document ).ready(function() {
		$("#role_login_form").submit(function(event) {
    		/* Stop form from submitting normally */
    		event.preventDefault();
    		$("#result").html('');
    		var f_role = $("#role_login_form").find('.role').val();
    		console.log("username:"+f_username+", password:"+f_password);
    		$.ajax({
        		url: baseurl+"/xhr-auth/selectRole.php?role="+f_role,
			dataType: "jsonp",
    			jsonp : "callback",
    			jsonpCallback: "xhr_login",
        		type: "get",
        		data: null,
        		success: function(data){
            			console.log("success:"+data);
            			$("#result").html('Submitted successfully');
	    			//document.location=landing_page;
				 $.mobile.changePage(landing_page); 
        		},
        		error:function(){
            			console.log("failure");
            			$("#result").html('There is error while submit');
        		}
    		});
		});
	});
}

//TODO
shape.logout = function(baseurl, landing_page){
	console.log("baseurl:"+baseurl);
	$( document ).ready(function() {
		$("#simple_login_form").submit(function(event) {
    		event.preventDefault();
    		$("#result").html('');
    		var f_username = $("#simple_login_form").find('.username').val();
    		var f_password = $("#simple_login_form").find('.password').val();
    		console.log("username:"+f_username+", password:"+f_password);
    		$.ajax({
        		url: baseurl+"/xhr-auth/login.php?username="+f_username+"&password="+f_password,
			dataType: "jsonp",
    			jsonp : "callback",
    			jsonpCallback: "xhr_login",
        		type: "get",
        		data: null,
        		success: function(data){
            			console.log("success:"+data);
            			$("#result").html('Submitted successfully');
        		},
        		error:function(){
            			console.log("failure");
            			$("#result").html('There is error while submit');
        		}
    		});
		});
	});
}
shape.getQueryParams=function(qs) {
    	qs = qs.split("+").join(" ");
    	var params = {}, tokens,
        re = /[?&]?([^=]+)=([^&]*)/g;

    	while (tokens = re.exec(qs)) {
        	params[decodeURIComponent(tokens[1])]
            	= decodeURIComponent(tokens[2]);
    	}
    	return params;
}

shape.urlParam = function(name){
	$( document ).ready(function() {
		$("interp_param").click(function(event) {
			var results = new RegExp('[\\?&]' + name + '=([^&#]*)').exec(window.location.href);
    			if (results==null){
       				return null;
    			} else{
       				return results[1] || 0;
    			}
		});
	});
}

shape.loadBlock = function(block_id, block_url, block_params){
	$( document ).ready(function() {
        	$( block_id ).load( block_url );
	});
}
