//Elevate <exefile> <arguments>
var command = WScript.Arguments.Item(0);
var argument = "";
for (var i = 1; i < WScript.Arguments.Count(); ++i){
  argument += WScript.Arguments.Item(i) + " ";
}
 
try{
  var shellapp = new ActiveXObject("Shell.Application");
  shellapp.ShellExecute(command, argument, null, "runas", 1);
}
catch(e){
  WScript.Echo("Something wrong: " + e.description);
}