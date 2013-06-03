qx.Class.define("zero.MainWindow",
{
  extend : qx.ui.window.Window,
 
    construct : function()
    {
      this.base(arguments, "zero")
       // hide the window buttons
      this.setShowClose(false);
      this.setShowMaximize(false);
      this.setShowMinimize(false);
    }
});
