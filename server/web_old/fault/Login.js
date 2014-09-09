Ext.onReady(function(){
	Ext.get('submit').on('submit', function(){
		var username = Ext.get('username');
		var password = Ext.get('password');
		var msg = Ext.get('loginMsg');
		
		msg.load({
			url: 'silent.php', // <-- replace with your url
			params: 'username=' + Ext.get('username').dom.value + 'password=' + Ext.get('password'),
			text: 'Updating...'
		});
		msg.show();
	});
});
