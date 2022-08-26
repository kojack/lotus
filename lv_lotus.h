/**
 * @file lv_lotus.h
 *
 */

#ifndef LV_LOTUS_H
#define LV_LOTUS_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../../../core/lv_obj.h"
#if LV_USE_LOTUS

/*********************
 *      DEFINES
 *********************/

#define LV_OBJ_FLAG_LOTUS_IN_NEW_CONCENTRIC   LV_OBJ_FLAG_LAYOUT_1
LV_EXPORT_CONST_INT(LV_OBJ_FLAG_LOTUS_IN_NEW_CONCENTRIC);

#define _LV_LOTUS_COLUMN        (1 << 0)
#define _LV_LOTUS_WRAP       (1 << 2)
#define _LV_LOTUS_REVERSE    (1 << 3)

/**********************
 *      TYPEDEFS
 **********************/

/*Can't include lv_obj.h because it includes this header file*/
struct _lv_obj_t;

typedef enum {
    LV_LOTUS_ALIGN_START,
    LV_LOTUS_ALIGN_END,
    LV_LOTUS_ALIGN_NOON,
    LV_LOTUS_ALIGN_SPACE_EVENLY,
    LV_LOTUS_ALIGN_SPACE_AROUND,
    LV_LOTUS_ALIGN_SPACE_BETWEEN,
}lv_lotus_align_t;

typedef enum {
    LV_LOTUS_FLOW_ROW                 = 0x00,
    LV_LOTUS_FLOW_COLUMN              = _LV_LOTUS_COLUMN,
    LV_LOTUS_FLOW_ROW_WRAP            = LV_LOTUS_FLOW_ROW | _LV_LOTUS_WRAP,
    LV_LOTUS_FLOW_ROW_REVERSE         = LV_LOTUS_FLOW_ROW | _LV_LOTUS_REVERSE,
    LV_LOTUS_FLOW_ROW_WRAP_REVERSE    = LV_LOTUS_FLOW_ROW | _LV_LOTUS_WRAP | _LV_LOTUS_REVERSE,
    LV_LOTUS_FLOW_COLUMN_WRAP         = LV_LOTUS_FLOW_COLUMN | _LV_LOTUS_WRAP,
    LV_LOTUS_FLOW_COLUMN_REVERSE      = LV_LOTUS_FLOW_COLUMN | _LV_LOTUS_REVERSE,
    LV_LOTUS_FLOW_COLUMN_WRAP_REVERSE = LV_LOTUS_FLOW_COLUMN | _LV_LOTUS_WRAP | _LV_LOTUS_REVERSE,
}lv_lotus_flow_t;

/**********************
 * GLOBAL VARIABLES
 **********************/
extern uint32_t LV_LAYOUT_LOTUS;
extern lv_style_prop_t LV_STYLE_LOTUS_FLOW;
extern lv_style_prop_t LV_STYLE_LOTUS_MAIN_PLACE;
extern lv_style_prop_t LV_STYLE_LOTUS_CROSS_PLACE;
extern lv_style_prop_t LV_STYLE_LOTUS_CONCENTRIC_PLACE;
extern lv_style_prop_t LV_STYLE_LOTUS_GROW;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize a lotus layout the default values
 * @param lotus pointer to a lotus layout descriptor
 */
void lv_lotus_init(void);

/**
 * Set hot the item should flow
 * @param lotus pointer to a lotus layout descriptor
 * @param flow an element of `lv_lotus_flow_t`.
 */
void lv_obj_set_lotus_flow(lv_obj_t * obj, lv_lotus_flow_t flow);

/**
 * Set how to place (where to align) the items an concentrics
 * @param lotus pointer: to a lotus layout descriptor
 * @param main_place where to place the items on main axis (in their concentric). Any value of `lv_lotus_align_t`.
 * @param cross_place where to place the item in their concentric on the cross axis. `LV_LOTUS_ALIGN_START/END/CENTER`
 * @param concentric_place where to place the concentrics in the cross direction. Any value of `lv_lotus_align_t`.
 */
void lv_obj_set_lotus_align(lv_obj_t * obj, lv_lotus_align_t main_place, lv_lotus_align_t cross_place, lv_lotus_align_t concentric_cross_place);

/**
 * Sets the width or height (on main axis) to grow the object in order fill the free space
 * @param obj pointer to an object. The parent must have lotus layout else nothing will happen.
 * @param grow a value to set how much free space to take proportionally to other growing items.
 */
void lv_obj_set_lotus_grow(lv_obj_t * obj, uint8_t grow);

void lv_style_set_lotus_flow(lv_style_t * style, lv_lotus_flow_t value);
void lv_style_set_lotus_main_place(lv_style_t * style, lv_lotus_align_t value);
void lv_style_set_lotus_cross_place(lv_style_t * style, lv_lotus_align_t value);
void lv_style_set_lotus_concentric_place(lv_style_t * style, lv_lotus_align_t value);
void lv_style_set_lotus_grow(lv_style_t * style, uint8_t value);
void lv_obj_set_style_lotus_flow(lv_obj_t * obj, lv_lotus_flow_t value, lv_style_selector_t selector);
void lv_obj_set_style_lotus_main_place(lv_obj_t * obj, lv_lotus_align_t value, lv_style_selector_t selector);
void lv_obj_set_style_lotus_cross_place(lv_obj_t * obj, lv_lotus_align_t value, lv_style_selector_t selector);
void lv_obj_set_style_lotus_concentric_place(lv_obj_t * obj, lv_lotus_align_t value, lv_style_selector_t selector);
void lv_obj_set_style_lotus_grow(lv_obj_t * obj, uint8_t value, lv_style_selector_t selector);

static inline lv_lotus_flow_t lv_obj_get_style_lotus_flow(const lv_obj_t * obj, uint32_t part)
{
    lv_style_value_t v = lv_obj_get_style_prop(obj, part, LV_STYLE_LOTUS_FLOW);
    return (lv_lotus_flow_t)v.num;
}

static inline lv_lotus_align_t lv_obj_get_style_lotus_main_place(const lv_obj_t * obj, uint32_t part)
{
    lv_style_value_t v = lv_obj_get_style_prop(obj, part, LV_STYLE_LOTUS_MAIN_PLACE);
    return (lv_lotus_align_t)v.num;
}

static inline lv_lotus_align_t lv_obj_get_style_lotus_cross_place(const lv_obj_t * obj, uint32_t part)
{
    lv_style_value_t v = lv_obj_get_style_prop(obj, part, LV_STYLE_LOTUS_CROSS_PLACE);
    return (lv_lotus_align_t)v.num;
}

static inline lv_lotus_align_t lv_obj_get_style_lotus_concentric_place(const lv_obj_t * obj, uint32_t part)
{
    lv_style_value_t v = lv_obj_get_style_prop(obj, part, LV_STYLE_LOTUS_CONCENTRIC_PLACE);
    return (lv_lotus_align_t)v.num;
}

static inline uint8_t lv_obj_get_style_lotus_grow(const lv_obj_t * obj, uint32_t part)
{
    lv_style_value_t v = lv_obj_get_style_prop(obj, part, LV_STYLE_LOTUS_GROW);
    return (uint8_t)v.num;
}


/**********************
 *      MACROS
 **********************/

#endif  /*LV_USE_LOTUS*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_LOTUS_H*/
