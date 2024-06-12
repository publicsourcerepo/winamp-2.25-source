/* This file was generated by Maki Compiler, do not edit manually */

#include <precomp.h>
#include <api/api.h>
#include "c_edit.h"
#include <api/script/objcontroller.h>

C_Edit::C_Edit(ScriptObject *object) : C_GuiObject(object) {
  inited = 0;
  C_hook(object);
}

C_Edit::C_Edit() {
  inited = 0;
}

void C_Edit::C_hook(ScriptObject *object) {
  ASSERT(!inited);
  ScriptObjectController *controller = object->vcpu_getController();
  obj = controller->cast(object, editGuid);
  if (obj != object && obj != NULL)
    controller = obj->vcpu_getController();
  else
    obj = NULL;

  int iter = WASABI_API_APP->app_getInitCount();
  if (!loaded || loaded != iter) {
    loaded = iter;
    onenter_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onEnter", this);
    onabort_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onAbort", this);
    onidleeditupdate_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onIdleEditUpdate", this);
    oneditupdate_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onEditUpdate", this);
    settext_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setText", this);
    setautoenter_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setAutoEnter", this);
    getautoenter_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getAutoEnter", this);
    gettext_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getText", this);
    selectall_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"selectAll", this);
    enter_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"enter", this);
    setidleenabled_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setIdleEnabled", this);
    getidleenabled_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getIdleEnabled", this);
  }
  inited = 1;
}

C_Edit::~C_Edit() {
}

ScriptObject *C_Edit::getScriptObject() {
  if (obj != NULL) return obj;
  return C_EDIT_PARENT::getScriptObject();
}

void C_Edit::onEnter() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onenter_id, NULL);
}

void C_Edit::onAbort() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onabort_id, NULL);
}

void C_Edit::onIdleEditUpdate() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onidleeditupdate_id, NULL);
}

void C_Edit::onEditUpdate() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), oneditupdate_id, NULL);
}

void C_Edit::setText(const wchar_t *txt) 
{
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_STRING(txt);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), settext_id, params);
}

void C_Edit::setAutoEnter(int onoff) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(onoff);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), setautoenter_id, params);
}

int C_Edit::getAutoEnter() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getautoenter_id, NULL));
}

const wchar_t *C_Edit::getText() 
{
  ASSERT(inited);
  return GET_SCRIPT_STRING(WASABI_API_MAKI->maki_callFunction(getScriptObject(), gettext_id, NULL));
}

void C_Edit::selectAll() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), selectall_id, NULL);
}

void C_Edit::enter() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), enter_id, NULL);
}

void C_Edit::setIdleEnabled(int onoff) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(onoff);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), setidleenabled_id, params);
}

int C_Edit::getIdleEnabled() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getidleenabled_id, NULL));
}

int C_Edit::loaded=0;
int C_Edit::onenter_id=0;
int C_Edit::onabort_id=0;
int C_Edit::onidleeditupdate_id=0;
int C_Edit::oneditupdate_id=0;
int C_Edit::settext_id=0;
int C_Edit::setautoenter_id=0;
int C_Edit::getautoenter_id=0;
int C_Edit::gettext_id=0;
int C_Edit::selectall_id=0;
int C_Edit::enter_id=0;
int C_Edit::setidleenabled_id=0;
int C_Edit::getidleenabled_id=0;
