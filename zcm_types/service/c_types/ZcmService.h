// THIS IS AN AUTOMATICALLY GENERATED FILE.
// DO NOT MODIFY BY HAND!!
//
// Generated by zcm-gen

#include <stdint.h>
#include <stdlib.h>
#include <zcm/zcm_coretypes.h>
#include <zcm/zcm.h>

#ifndef _ZcmService_h
#define _ZcmService_h

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct ZcmService
 * @brief Служебное сообщение
 * @var ZcmService::u_timestamp
 * @brief - время получения данных, микросекунды
 * @var ZcmService::processing_time
 * @brief - время обработки данных, микросекунды
 *
 */
typedef struct _ZcmService ZcmService;
struct _ZcmService
{
    int64_t    u_timestamp;
    int32_t    processing_time;
};

/**
 * Create a deep copy of a ZcmService.
 * When no longer needed, destroy it with ZcmService_destroy()
 */
ZcmService* ZcmService_copy(const ZcmService* to_copy);

/**
 * Destroy an instance of ZcmService created by ZcmService_copy()
 */
void ZcmService_destroy(ZcmService* to_destroy);

/**
 * Identifies a single subscription.  This is an opaque data type.
 */
typedef struct _ZcmService_subscription_t ZcmService_subscription_t;

/**
 * Prototype for a callback function invoked when a message of type
 * ZcmService is received.
 */
typedef void(*ZcmService_handler_t)(const zcm_recv_buf_t* rbuf,
             const char* channel, const ZcmService* msg, void* userdata);

/**
 * Publish a message of type ZcmService using ZCM.
 *
 * @param zcm The ZCM instance to publish with.
 * @param channel The channel to publish on.
 * @param msg The message to publish.
 * @return 0 on success, <0 on error.  Success means ZCM has transferred
 * responsibility of the message data to the OS.
 */
int ZcmService_publish(zcm_t* zcm, const char* channel, const ZcmService* msg);

/**
 * Subscribe to messages of type ZcmService using ZCM.
 *
 * @param zcm The ZCM instance to subscribe with.
 * @param channel The channel to subscribe to.
 * @param handler The callback function invoked by ZCM when a message is received.
 *                This function is invoked by ZCM during calls to zcm_handle() and
 *                zcm_handle_timeout().
 * @param userdata An opaque pointer passed to @p handler when it is invoked.
 * @return pointer to subscription type, NULL if failure. Must clean up
 *         dynamic memory by passing the pointer to ZcmService_unsubscribe.
 */
ZcmService_subscription_t* ZcmService_subscribe(zcm_t* zcm, const char* channel, ZcmService_handler_t handler, void* userdata);

/**
 * Removes and destroys a subscription created by ZcmService_subscribe()
 */
int ZcmService_unsubscribe(zcm_t* zcm, ZcmService_subscription_t* hid);
/**
 * Encode a message of type ZcmService into binary form.
 *
 * @param buf The output buffer.
 * @param offset Encoding starts at this byte offset into @p buf.
 * @param maxlen Maximum number of bytes to write.  This should generally
 *               be equal to ZcmService_encoded_size().
 * @param msg The message to encode.
 * @return The number of bytes encoded, or <0 if an error occured.
 */
int ZcmService_encode(void* buf, uint32_t offset, uint32_t maxlen, const ZcmService* p);

/**
 * Decode a message of type ZcmService from binary form.
 * When decoding messages containing strings or variable-length arrays, this
 * function may allocate memory.  When finished with the decoded message,
 * release allocated resources with ZcmService_decode_cleanup().
 *
 * @param buf The buffer containing the encoded message
 * @param offset The byte offset into @p buf where the encoded message starts.
 * @param maxlen The maximum number of bytes to read while decoding.
 * @param msg Output parameter where the decoded message is stored
 * @return The number of bytes decoded, or <0 if an error occured.
 */
int ZcmService_decode(const void* buf, uint32_t offset, uint32_t maxlen, ZcmService* msg);

/**
 * Release resources allocated by ZcmService_decode()
 * @return 0
 */
int ZcmService_decode_cleanup(ZcmService* p);

/**
 * Check how many bytes are required to encode a message of type ZcmService
 */
uint32_t ZcmService_encoded_size(const ZcmService* p);
uint32_t ZcmService_struct_size(void);
uint32_t ZcmService_num_fields(void);
int      ZcmService_get_field(const ZcmService* p, uint32_t i, zcm_field_t* f);
const zcm_type_info_t* ZcmService_get_type_info(void);

// ZCM support functions. Users should not call these
int64_t  __ZcmService_get_hash(void);
uint64_t __ZcmService_hash_recursive(const __zcm_hash_ptr* p);
int      __ZcmService_encode_array(void* buf, uint32_t offset, uint32_t maxlen, const ZcmService* p, uint32_t elements);
int      __ZcmService_decode_array(const void* buf, uint32_t offset, uint32_t maxlen, ZcmService* p, uint32_t elements);
int      __ZcmService_decode_array_cleanup(ZcmService* p, uint32_t elements);
uint32_t __ZcmService_encoded_array_size(const ZcmService* p, uint32_t elements);
uint32_t __ZcmService_clone_array(const ZcmService* p, ZcmService* q, uint32_t elements);

#ifdef __cplusplus
}
#endif

#endif
