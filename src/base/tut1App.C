#include "tut1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
tut1App::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

tut1App::tut1App(InputParameters parameters) : MooseApp(parameters)
{
  tut1App::registerAll(_factory, _action_factory, _syntax);
}

tut1App::~tut1App() {}

void
tut1App::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"tut1App"});
  Registry::registerActionsTo(af, {"tut1App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
tut1App::registerApps()
{
  registerApp(tut1App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
tut1App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  tut1App::registerAll(f, af, s);
}
extern "C" void
tut1App__registerApps()
{
  tut1App::registerApps();
}
