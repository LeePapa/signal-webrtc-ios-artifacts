/*
 *
 *  Copyright (C) 2019 Signal Messenger, LLC.
 *  All rights reserved.
 *
 *  SPDX-License-Identifier: GPL-3.0-only
 *
 */

#ifndef CBINDGEN_BINDINGS_H
#define CBINDGEN_BINDINGS_H

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * Incomplete type for C++ PeerConnectionInterface.
 */
typedef struct {
    uint8_t _private[0];
} RffiPeerConnectionInterface;

/**
 * Opaque pointer type for an object of C++ origin.
 */
typedef const void *CppObject;

/**
 * Incomplete type for C++ webrtc::rffi::CreateSessionDescriptionObserverRffi
 */
typedef struct {
    uint8_t _private[0];
} RffiCreateSessionDescriptionObserver;

/**
 * Opaque pointer type for an object of Rust origin.
 */
typedef const void *RustObject;

/**
 * Incomplete type for C++ DataChannelInterface.
 */
typedef struct {
    uint8_t _private[0];
} RffiDataChannelInterface;

/**
 * Rust friendly version of WebRTC DataChannelInit.
 *
 * The definition is taken from [WebRTC RTCDataChannelInit]
 * (https://www.w3.org/TR/webrtc/#idl-def-rtcdatachannelinit).
 *
 * See `struct DataChannelInit1 in
 * webrtc/src/api/data_channel_interface.h
 */
typedef struct {
    bool reliable;
    bool ordered;
    int maxRetransmitTime;
    int maxRetransmits;
    const char *protocol;
    bool negotiated;
    int id;
} RffiDataChannelInit;

/**
 * Incomplete type for C++ DataChannelObserver.
 */
typedef struct {
    uint8_t _private[0];
} RffiDataChannelObserverInterface;

#if defined(TARGET_OS_ANDROID)
/**
 * Incomplete type for C++ JavaMediaStream.
 */
typedef struct {
    uint8_t _private[0];
} RffiJavaMediaStream;
#endif

/**
 * Incomplete type for WebRTC C++ MediaStreamInterface.
 */
typedef struct {
    uint8_t _private[0];
} RffiMediaStreamInterface;

/**
 * Incomplete type for C++ PeerConnectionObserver.
 */
typedef struct {
    uint8_t _private[0];
} RffiPeerConnectionObserverInterface;

/**
 * Incomplete type for SessionDescriptionInterface, used by
 * CreateSessionDescriptionObserver callbacks.
 */
typedef struct {
    uint8_t _private[0];
} RffiSessionDescriptionInterface;

/**
 * Incomplete type for C++ CreateSessionDescriptionObserverRffi
 */
typedef struct {
    uint8_t _private[0];
} RffiSetSessionDescriptionObserver;

#if defined(TARGET_OS_IOS)
/**
 * Structure for passing buffers (such as strings) to Swift.
 */
typedef struct {
    const uint8_t *bytes;
    size_t len;
} AppByteSlice;
#endif

#if defined(TARGET_OS_IOS)
/**
 * Structure for passing Ice Candidates to/from Swift.
 */
typedef struct {
    AppByteSlice sdpMid;
    int32_t sdpMLineIndex;
    AppByteSlice sdp;
} AppIceCandidate;
#endif

#if defined(TARGET_OS_IOS)
/**
 * Structure for passing multiple Ice Candidates to Swift.
 */
typedef struct {
    const AppIceCandidate *candidates;
    size_t count;
} AppIceCandidateArray;
#endif

#if defined(TARGET_OS_IOS)
/**
 * Structure for passing connection details from the application.
 */
typedef struct {
    void *object;
    void *pc;
    /**
     * Swift object clean up method.
     */
    void (*destroy)(void *object);
} AppConnectionInterface;
#endif

#if defined(TARGET_OS_IOS)
/**
 * Structure for passing media stream instances from the application.
 */
typedef struct {
    void *object;
    /**
     * Swift object clean up method.
     */
    void (*destroy)(void *object);
    /**
     * Returns a pointer to a RTCMediaStream object.
     */
    void *(*createMediaStream)(void *object, void *nativeStream);
} AppMediaStreamInterface;
#endif

#if defined(TARGET_OS_IOS)
/**
 * iOS Interface for communicating with the Swift application.
 */
typedef struct {
    /**
     * Raw Swift object pointer.
     */
    void *object;
    /**
     * Swift object clean up method.
     */
    void (*destroy)(void *object);
    /**
     *
     */
    void (*onStartCall)(void *object, const void *remote, uint64_t callId, bool isOutgoing);
    /**
     * Swift event callback method.
     */
    void (*onEvent)(void *object, const void *remote, int32_t event);
    /**
     *
     */
    void (*onSendOffer)(void *object, uint64_t callId, const void *remote, uint32_t deviceId, bool broadcast, AppByteSlice offer);
    /**
     *
     */
    void (*onSendAnswer)(void *object, uint64_t callId, const void *remote, uint32_t deviceId, bool broadcast, AppByteSlice answer);
    /**
     *
     */
    void (*onSendIceCandidates)(void *object, uint64_t callId, const void *remote, uint32_t deviceId, bool broadcast, const AppIceCandidateArray *candidates);
    /**
     *
     */
    void (*onSendHangup)(void *object, uint64_t callId, const void *remote, uint32_t deviceId, bool broadcast);
    /**
     *
     */
    void (*onSendBusy)(void *object, uint64_t callId, const void *remote, uint32_t deviceId, bool broadcast);
    /**
     *
     */
    AppConnectionInterface (*onCreateConnectionInterface)(void *object, void *observer, uint32_t deviceId, void *context);
    /**
     * Request that the application create an application Media Stream object
     * associated with the given application Connection object.
     */
    AppMediaStreamInterface (*onCreateMediaStreamInterface)(void *object, void *connection);
    /**
     *
     */
    void (*onConnectMedia)(void *object, const void *remote, void *context, const void *stream);
    /**
     *
     */
    bool (*onCompareRemotes)(void *object, const void *remote1, const void *remote2);
    /**
     *
     */
    void (*onCallConcluded)(void *object, const void *remote);
} AppInterface;
#endif

#if defined(TARGET_OS_IOS)
/**
 * Log object for interfacing with swift.
 */
typedef struct {
    void *object;
    void (*destroy)(void *object);
    void (*log)(void *object, AppByteSlice message, AppByteSlice file, AppByteSlice function, int32_t line, int8_t level);
} IOSLogger;
#endif

#if defined(TARGET_OS_IOS)
/**
 * Structure for holding call context details on behalf of the application.
 */
typedef struct {
    void *object;
    /**
     * Swift object clean up method.
     */
    void (*destroy)(void *object);
} AppCallContext;
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcAcceptCall(JNIEnv env,
                                                           JObject _object,
                                                           jlong call_manager,
                                                           jlong call_id);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcCall(JNIEnv env,
                                                     JObject _object,
                                                     jlong call_manager,
                                                     JObject jni_remote);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcClose(JNIEnv env,
                                                      JObject _object,
                                                      jlong call_manager);
#endif

#if defined(TARGET_OS_ANDROID)
jlong Java_org_signal_ringrtc_CallManager_ringrtcCreateCallManager(JNIEnv env,
                                                                   JClass _class,
                                                                   JObject jni_call_manager);
#endif

#if defined(TARGET_OS_ANDROID)
jlong Java_org_signal_ringrtc_CallManager_ringrtcCreatePeerConnection(JNIEnv env,
                                                                      JObject _object,
                                                                      jlong peer_connection_factory,
                                                                      jlong native_connection,
                                                                      JObject jni_rtc_config,
                                                                      JObject jni_media_constraints);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcDrop(JNIEnv env,
                                                     JObject _object,
                                                     jlong call_manager,
                                                     jlong call_id);
#endif

#if defined(TARGET_OS_ANDROID)
jobject Java_org_signal_ringrtc_CallManager_ringrtcGetActiveCallContext(JNIEnv env,
                                                                        JObject _object,
                                                                        jlong call_manager);
#endif

#if defined(TARGET_OS_ANDROID)
jobject Java_org_signal_ringrtc_CallManager_ringrtcGetActiveConnection(JNIEnv env,
                                                                       JObject _object,
                                                                       jlong call_manager);
#endif

#if defined(TARGET_OS_ANDROID)
jobject Java_org_signal_ringrtc_CallManager_ringrtcGetBuildInfo(JNIEnv env, JClass _class);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcHangup(JNIEnv env,
                                                       JObject _object,
                                                       jlong call_manager);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcInitialize(JNIEnv env, JClass _class);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcMessageSendFailure(JNIEnv env,
                                                                   JObject _object,
                                                                   jlong call_manager,
                                                                   jlong call_id);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcMessageSent(JNIEnv env,
                                                            JObject _object,
                                                            jlong call_manager,
                                                            jlong call_id);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcProceed(JNIEnv env,
                                                        JObject _object,
                                                        jlong call_manager,
                                                        jlong call_id,
                                                        JObject jni_call_context,
                                                        JObject jni_remote_devices);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcReceivedAnswer(JNIEnv env,
                                                               JObject _object,
                                                               jlong call_manager,
                                                               jlong call_id,
                                                               jint remote_device,
                                                               JString jni_answer);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcReceivedBusy(JNIEnv env,
                                                             JObject _object,
                                                             jlong call_manager,
                                                             jlong call_id,
                                                             jint remote_device);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcReceivedHangup(JNIEnv env,
                                                               JObject _object,
                                                               jlong call_manager,
                                                               jlong call_id,
                                                               jint remote_device);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcReceivedIceCandidates(JNIEnv env,
                                                                      JObject _object,
                                                                      jlong call_manager,
                                                                      jlong call_id,
                                                                      jint remote_device,
                                                                      JObject jni_ice_candidates);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcReceivedOffer(JNIEnv env,
                                                              JObject _object,
                                                              jlong call_manager,
                                                              jlong call_id,
                                                              JObject jni_remote,
                                                              jint remote_device,
                                                              JString jni_offer,
                                                              jlong timestamp);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcReset(JNIEnv env,
                                                      JObject _object,
                                                      jlong call_manager);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallManager_ringrtcSetVideoEnable(JNIEnv env,
                                                               JObject _object,
                                                               jlong call_manager,
                                                               jboolean enable);
#endif

#if defined(TARGET_OS_ANDROID)
/**
 * Export the nativeCreatepeerconnection() call from the
 * org.webrtc.PeerConnectionFactory class.
 */
extern jlong Java_org_webrtc_PeerConnectionFactory_nativeCreatePeerConnection(JNIEnv env,
                                                                              JClass class_,
                                                                              jlong factory,
                                                                              JObject rtcConfig,
                                                                              JObject constraints,
                                                                              jlong nativeObserver,
                                                                              JObject sslCertificateVerifier);
#endif

extern bool Rust_addIceCandidate(const RffiPeerConnectionInterface *pc_interface,
                                 const char *sdp_mid,
                                 int32_t sdp_mline_index,
                                 const char *sdp);

extern void Rust_addRef(CppObject ref_counted_pointer);

extern void Rust_createAnswer(const RffiPeerConnectionInterface *pc_interface,
                              const RffiCreateSessionDescriptionObserver *csd_observer);

extern const RffiCreateSessionDescriptionObserver *Rust_createCreateSessionDescriptionObserver(RustObject csd_observer,
                                                                                               const void *csd_observer_cb);

extern const RffiDataChannelInterface *Rust_createDataChannel(const RffiPeerConnectionInterface *pc_interface,
                                                              const char *label,
                                                              const RffiDataChannelInit *config);

extern const RffiDataChannelObserverInterface *Rust_createDataChannelObserver(RustObject call_connection,
                                                                              CppObject dc_observer_cb);

#if defined(TARGET_OS_ANDROID)
extern const RffiJavaMediaStream *Rust_createJavaMediaStream(const RffiMediaStreamInterface *media_stream_interface);
#endif

extern void Rust_createOffer(const RffiPeerConnectionInterface *pc_interface,
                             const RffiCreateSessionDescriptionObserver *csd_observer);

extern const RffiPeerConnectionObserverInterface *Rust_createPeerConnectionObserver(RustObject cc_ptr,
                                                                                    CppObject pc_observer_cb);

extern const RffiSessionDescriptionInterface *Rust_createSessionDescriptionAnswer(const char *description);

extern const RffiSessionDescriptionInterface *Rust_createSessionDescriptionOffer(const char *description);

extern const RffiSetSessionDescriptionObserver *Rust_createSetSessionDescriptionObserver(RustObject ssd_observer,
                                                                                         const void *ssd_observer_cb);

extern const char *Rust_dataChannelGetLabel(const RffiDataChannelInterface *dc_interface);

extern bool Rust_dataChannelSend(const RffiDataChannelInterface *dc_interface,
                                 const uint8_t *buffer,
                                 size_t len,
                                 bool binary);

#if defined(TARGET_OS_ANDROID)
extern void Rust_freeJavaMediaStream(const RffiJavaMediaStream *rffi_jms_interface);
#endif

#if defined(TARGET_OS_ANDROID)
extern jobject Rust_getObjectJavaMediaStream(const RffiJavaMediaStream *rffi_jms_interface);
#endif

extern const char *Rust_getOfferDescription(const RffiSessionDescriptionInterface *offer);

#if defined(TARGET_OS_ANDROID)
extern const RffiPeerConnectionInterface *Rust_getPeerConnectionInterface(int64_t jni_owned_pc);
#endif

extern void Rust_registerDataChannelObserver(const RffiDataChannelInterface *dc_interface,
                                             const RffiDataChannelObserverInterface *dc_observer);

extern void Rust_releaseRef(CppObject ref_counted_pointer);

extern void Rust_setLocalDescription(const RffiPeerConnectionInterface *pc_interface,
                                     const RffiSetSessionDescriptionObserver *ssd_observer,
                                     const RffiSessionDescriptionInterface *desc);

extern void Rust_setRemoteDescription(const RffiPeerConnectionInterface *pc_interface,
                                      const RffiSetSessionDescriptionObserver *ssd_observer,
                                      const RffiSessionDescriptionInterface *desc);

extern void Rust_unregisterDataChannelObserver(const RffiDataChannelInterface *dc_interface,
                                               const RffiDataChannelObserverInterface *dc_observer);

#if defined(TARGET_OS_IOS)
void *ringrtcAccept(void *callManager, uint64_t callId);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcCall(void *callManager, const void *appRemote);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcClose(void *callManager);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcCreate(void *appCallManager, AppInterface appInterface);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcDrop(void *callManager, uint64_t callId);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcGetActiveCallContext(void *callManager);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcGetActiveConnection(void *callManager);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcHangup(void *callManager);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcInitialize(IOSLogger logObject);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcMessageSendFailure(void *callManager, uint64_t callId);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcMessageSent(void *callManager, uint64_t callId);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcProceed(void *callManager,
                     uint64_t callId,
                     AppCallContext appCallContext,
                     const uint32_t *appRemoteDevices,
                     size_t appRemoteDevicesLen);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcReceivedAnswer(void *callManager,
                            uint64_t callId,
                            uint32_t remoteDevice,
                            AppByteSlice answer);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcReceivedBusy(void *callManager, uint64_t callId, uint32_t remoteDevice);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcReceivedHangup(void *callManager, uint64_t callId, uint32_t remoteDevice);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcReceivedIceCandidates(void *callManager,
                                   uint64_t callId,
                                   uint32_t remoteDevice,
                                   const AppIceCandidateArray *appIceCandidateArray);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcReceivedOffer(void *callManager,
                           uint64_t callId,
                           const void *appRemote,
                           uint32_t remoteDevice,
                           AppByteSlice offer,
                           uint64_t timestamp);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcReset(void *callManager);
#endif

#if defined(TARGET_OS_IOS)
void *ringrtcSetVideoEnable(void *callManager, bool enable);
#endif

#endif /* CBINDGEN_BINDINGS_H */
