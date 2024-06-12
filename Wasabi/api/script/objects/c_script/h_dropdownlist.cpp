/* This file was generated by Maki Compiler, do not edit manually */

#include <precomp.h>
#include <api/api.h>
#include <api/script/objcontroller.h>
#include "h_dropdownlist.h"

H_DropDownList::H_DropDownList(ScriptObject *o) : H_GuiObject(o) {
  inited=0;
  H_hook(o);
}

H_DropDownList::H_DropDownList() {
  inited=0;
}

void H_DropDownList::H_hook(ScriptObject *o) {
  ASSERT(!inited);
  ScriptObjectController *controller = o->vcpu_getController();
  obj = controller->cast(o, dropDownListGuid);
  if (obj != o && obj != NULL)
    o = obj;
  else
    obj = NULL;

  addMonitorObject(o, &dropDownListGuid);

  int iter = WASABI_API_APP->app_getInitCount();
  if (!loaded || loaded != iter) {
    onselect_id= WASABI_API_MAKI->maki_addDlfRef(o->vcpu_getController(), L"onSelect", this);
    loaded = 1;
  }
  inited=1;
}

H_DropDownList::~H_DropDownList() {
  if (!inited) return;
  WASABI_API_MAKI->maki_remDlfRef(this);
}

ScriptObject *H_DropDownList::getHookedObject() {
  if (obj != NULL) return obj;
  return H_DROPDOWNLIST_PARENT::getHookedObject();
}

int H_DropDownList::eventCallback(ScriptObject *object, int dlfid, scriptVar **params, int nparams) {
  if (object != getHookedObject()) return 0;
  if (H_DROPDOWNLIST_PARENT::eventCallback(object, dlfid, params, nparams)) return 1;
  if (dlfid == onselect_id) { hook_onSelect(GET_SCRIPT_INT(*params[0]), GET_SCRIPT_INT(*params[1])); return 1; }
  return 0;
}

int H_DropDownList::onselect_id=0;
int H_DropDownList::loaded=0;
