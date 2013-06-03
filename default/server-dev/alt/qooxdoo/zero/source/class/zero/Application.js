/* ************************************************************************

   Copyright:

   License:

   Authors:

************************************************************************ */

/* ************************************************************************

#asset(zero/*)

************************************************************************ */

/**
 * This is the main application class of your custom application "zero"
 */
qx.Class.define("zero.Application",
{
  extend : qx.application.Standalone,



  /*
  *****************************************************************************
     MEMBERS
  *****************************************************************************
  */

  members :
  {
    /**
     * This method contains the initial application code and gets called 
     * during startup of the application
     * 
     * @lint ignoreDeprecated(alert)
     */
    main : function()
    {
      // Call super class
      this.base(arguments);

      // Enable logging in debug variant
      if (qx.core.Variant.isSet("qx.debug", "on"))
      {
        // support native logging capabilities, e.g. Firebug for Firefox
        qx.log.appender.Native;
        // support additional cross-browser console. Press F7 to toggle visibility
        qx.log.appender.Console;
      }
      /*****************************************************************************/
      var main = new zero.MainWindow();
      main.moveTo(50, 30);
      main.setWidth(250);
      main.setHeight(300);
   // hide the window buttons
      main.open();
      /*
      var sec = new zero.MainWindow();
      sec.moveTo(150, 130);
      sec.open();
      */
      /*****************************************************************************/

    }
  }
});
