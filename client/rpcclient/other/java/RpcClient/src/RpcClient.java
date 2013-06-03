import java.net.URL;

import org.apache.xmlrpc.client.XmlRpcClient;
import org.apache.xmlrpc.client.XmlRpcClientConfigImpl;

public class RpcClient
{

public static void main(String s[]){

	final String urlString = "http://ws.hackbook.org/rpc/crud.php";
    XmlRpcClientConfigImpl config;
    try{
    	config = new XmlRpcClientConfigImpl();
    	config.setServerURL(new URL(urlString));
    	XmlRpcClient client = new XmlRpcClient();
    	client.setConfig(config);
    	Object[] params = new Object[]{new String("Uno"), new String("Due")};
    	String result = (String) client.execute("test.connection", params);
    }catch (Exception e) {
		System.out.println(""+e);
	}
}


}
