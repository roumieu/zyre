/*  =========================================================================
    zyre_event - Parsing Zyre messages

    Copyright (c) the Contributors as noted in the AUTHORS file.           
                                                                           
    This file is part of Zyre, an open-source framework for proximity-based
    peer-to-peer applications -- See http://zyre.org.                      
                                                                           
    This Source Code Form is subject to the terms of the Mozilla Public    
    License, v. 2.0. If a copy of the MPL was not distributed with this    
    file, You can obtain one at http://mozilla.org/MPL/2.0/.               
    =========================================================================
*/

#ifndef ZYRE_EVENT_H_INCLUDED
#define ZYRE_EVENT_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


//  @warning THE FOLLOWING @INTERFACE BLOCK IS AUTO-GENERATED BY ZPROJECT
//  @warning Please edit the model at "api/zyre_event.xml" to make changes.
//  @interface
//  This is a draft class, and may change without notice. It is disabled in
//  stable builds by default. If you use this in applications, please ask
//  for it to be pushed to stable state. Use --enable-drafts to enable.
//  Self test of this class.
ZYRE_EXPORT void
    zyre_event_test (bool verbose);

#ifdef ZYRE_BUILD_DRAFT_API
// 
typedef enum {
    ZYRE_EVENT_ENTER = 1,                                   //  
    ZYRE_EVENT_JOIN = 2,                                    //  
    ZYRE_EVENT_LEAVE = 3,                                   //  
    ZYRE_EVENT_EXIT = 4,                                    //  
    ZYRE_EVENT_WHISPER = 5,                                 //  
    ZYRE_EVENT_SHOUT = 6,                                   //  
    ZYRE_EVENT_STOP = 7,                                    //  
    ZYRE_EVENT_EVASIVE = 8                                  //  
} zyre_event_type_t;

//  *** Draft method, for development use, may change without warning ***
//  Constructor: receive an event from the zyre node, wraps zyre_recv.
//  The event may be a control message (ENTER, EXIT, JOIN, LEAVE) or  
//  data (WHISPER, SHOUT).                                            
ZYRE_EXPORT zyre_event_t *
    zyre_event_new (zyre_t *node);

//  *** Draft method, for development use, may change without warning ***
//  Destructor; destroys an event instance
ZYRE_EXPORT void
    zyre_event_destroy (zyre_event_t **self_p);

//  *** Draft method, for development use, may change without warning ***
//  Returns event type, which is a zyre_event_type_t
ZYRE_EXPORT zyre_event_type_t
    zyre_event_type (zyre_event_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Return the sending peer's id as a string
ZYRE_EXPORT const char *
    zyre_event_sender (zyre_event_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Return the sending peer's public name as a string
ZYRE_EXPORT const char *
    zyre_event_name (zyre_event_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Return the sending peer's ipaddress as a string
ZYRE_EXPORT const char *
    zyre_event_address (zyre_event_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Returns the event headers, or NULL if there are none
ZYRE_EXPORT zhash_t *
    zyre_event_headers (zyre_event_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Returns value of a header from the message headers   
//  obtained by ENTER. Return NULL if no value was found.
ZYRE_EXPORT const char *
    zyre_event_header (zyre_event_t *self, const char *name);

//  *** Draft method, for development use, may change without warning ***
//  Returns the group name that a SHOUT event was sent to
ZYRE_EXPORT const char *
    zyre_event_group (zyre_event_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Returns the incoming message payload (currently one frame)
ZYRE_EXPORT zmsg_t *
    zyre_event_msg (zyre_event_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Print event to zsys log
ZYRE_EXPORT void
    zyre_event_print (zyre_event_t *self);

#endif // ZYRE_BUILD_DRAFT_API
//  @end

#ifdef __cplusplus
}
#endif

#endif
