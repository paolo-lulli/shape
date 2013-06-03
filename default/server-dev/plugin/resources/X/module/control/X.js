
Ext.onReady(function(){
        //Ext.get('okButton').on('click', function(){
        Ext.get('Xname').on('change', function(){
                var msg = Ext.get('Xmsg');
                msg.load({
                        url: 'call.php', // <-- change if necessary
                        params: 'name=' + Ext.get('name').dom.value,
                        text: 'Updating...'
                });
                msg.show();
        });
});
