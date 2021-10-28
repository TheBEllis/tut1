//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "tut1TestApp.h"
#include "tut1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
tut1TestApp::validParams()
{
  InputParameters params = tut1App::validParams();
  return params;
}

tut1TestApp::tut1TestApp(InputParameters parameters) : MooseApp(parameters)
{
  tut1TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

tut1TestApp::~tut1TestApp() {}

void
tut1TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  tut1App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"tut1TestApp"});
    Registry::registerActionsTo(af, {"tut1TestApp"});
  }
}

void
tut1TestApp::registerApps()
{
  registerApp(tut1App);
  registerApp(tut1TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
tut1TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  tut1TestApp::registerAll(f, af, s);
}
extern "C" void
tut1TestApp__registerApps()
{
  tut1TestApp::registerApps();
}
