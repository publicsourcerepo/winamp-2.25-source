/* This file was generated by Maki Compiler, do not edit manually */

#include <precomp.h>
#include <api/api.h>
#include "c_dropdownlist.h"
#include <api/script/objcontroller.h>

C_DropDownList::C_DropDownList(ScriptObject *object) : C_GuiObject(object) {
  inited = 0;
  C_hook(object);
}

C_DropDownList::C_DropDownList() {
  inited = 0;
}

void C_DropDownList::C_hook(ScriptObject *object) {
  ASSERT(!inited);
  ScriptObjectController *controller = object->vcpu_getController();
  obj = controller->cast(object, dropDownListGuid);
  if (obj != object && obj != NULL)
    controller = obj->vcpu_getController();
  else
    obj = NULL;

  int iter = WASABI_API_APP->app_getInitCount();
  if (!loaded || loaded != iter) {
    loaded = iter;
    getitemselected_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getItemSelected", this);
    onselect_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onSelect", this);
    setlistheight_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setListHeight", this);
    openlist_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"openList", this);
    closelist_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"closeList", this);
    setitems_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setItems", this);
    additem_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"addItem", this);
    delitem_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"delItem", this);
    finditem_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"findItem", this);
    getnumitems_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getNumItems", this);
    selectitem_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"selectItem", this);
    getitemtext_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getItemText", this);
    getselected_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getSelected", this);
    getselectedtext_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getSelectedText", this);
    getcustomtext_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getCustomText", this);
    deleteallitems_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"deleteAllItems", this);
    setnoitemtext_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setNoItemText", this);
  }
  inited = 1;
}

C_DropDownList::~C_DropDownList() {
}

ScriptObject *C_DropDownList::getScriptObject() {
  if (obj != NULL) return obj;
  return C_DROPDOWNLIST_PARENT::getScriptObject();
}

const wchar_t *C_DropDownList::getItemSelected() 
{
  ASSERT(inited);
  return GET_SCRIPT_STRING(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getitemselected_id, NULL));
}

void C_DropDownList::onSelect(int id, int hover) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(id);
  scriptVar b = MAKE_SCRIPT_INT(hover);
  scriptVar *params[2] = {&a, &b};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onselect_id, params);
}

void C_DropDownList::setListHeight(int h) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(h);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), setlistheight_id, params);
}

void C_DropDownList::openList() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), openlist_id, NULL);
}

void C_DropDownList::closeList() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), closelist_id, NULL);
}

void C_DropDownList::setItems(const wchar_t *lotsofitems) 
{
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_STRING(lotsofitems);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), setitems_id, params);
}

int C_DropDownList::addItem(const wchar_t *_text) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_STRING(_text);
  scriptVar *params[1] = {&a};
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), additem_id, params));
}

void C_DropDownList::delItem(int id) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(id);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), delitem_id, params);
}

int C_DropDownList::findItem(const wchar_t *_text) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_STRING(_text);
  scriptVar *params[1] = {&a};
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), finditem_id, params));
}

int C_DropDownList::getNumItems() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getnumitems_id, NULL));
}

void C_DropDownList::selectItem(int id, int hover) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(id);
  scriptVar b = MAKE_SCRIPT_INT(hover);
  scriptVar *params[2] = {&a, &b};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), selectitem_id, params);
}

const wchar_t *C_DropDownList::getItemText(int id) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(id);
  scriptVar *params[1] = {&a};
  return GET_SCRIPT_STRING(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getitemtext_id, params));
}

int C_DropDownList::getSelected() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getselected_id, NULL));
}

const wchar_t *C_DropDownList::getSelectedText() {
  ASSERT(inited);
  return GET_SCRIPT_STRING(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getselectedtext_id, NULL));
}

const wchar_t *C_DropDownList::getCustomText() {
  ASSERT(inited);
  return GET_SCRIPT_STRING(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getcustomtext_id, NULL));
}

void C_DropDownList::deleteAllItems() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), deleteallitems_id, NULL);
}

void C_DropDownList::setNoItemText(const wchar_t *txt) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_STRING(txt);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), setnoitemtext_id, params);
}

int C_DropDownList::loaded=0;
int C_DropDownList::getitemselected_id=0;
int C_DropDownList::onselect_id=0;
int C_DropDownList::setlistheight_id=0;
int C_DropDownList::openlist_id=0;
int C_DropDownList::closelist_id=0;
int C_DropDownList::setitems_id=0;
int C_DropDownList::additem_id=0;
int C_DropDownList::delitem_id=0;
int C_DropDownList::finditem_id=0;
int C_DropDownList::getnumitems_id=0;
int C_DropDownList::selectitem_id=0;
int C_DropDownList::getitemtext_id=0;
int C_DropDownList::getselected_id=0;
int C_DropDownList::getselectedtext_id=0;
int C_DropDownList::getcustomtext_id=0;
int C_DropDownList::deleteallitems_id=0;
int C_DropDownList::setnoitemtext_id=0;
