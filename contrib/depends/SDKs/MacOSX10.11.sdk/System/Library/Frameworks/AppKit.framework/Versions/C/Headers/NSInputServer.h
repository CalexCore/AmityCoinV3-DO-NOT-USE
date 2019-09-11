/*
	NSInputServer.h
	Application Kit
	Copyright (c) 1994-2015, Apple Inc.
	All rights reserved.
*/

#import <Foundation/NSObject.h>
#import <Foundation/NSGeometry.h>
#import <Foundation/NSRange.h>

/* These methods must be implemented by the delegate.
*/
NS_ASSUME_NONNULL_BEGIN

@protocol NSInputServiceProvider

- (void) insertText:(null_unspecified id)aString client:(null_unspecified id)sender NS_DEPRECATED_MAC(10_0, 10_6);
- (void) doCommandBySelector:(null_unspecified SEL)aSelector client:(null_unspecified id)sender NS_DEPRECATED_MAC(10_0, 10_6);
- (void) markedTextAbandoned:(nullable id)sender NS_DEPRECATED_MAC(10_0, 10_6);
- (void) markedTextSelectionChanged:(NSRange)newSel client:(null_unspecified id)sender NS_DEPRECATED_MAC(10_0, 10_6);
- (void) terminate:(nullable id)sender NS_DEPRECATED_MAC(10_0, 10_6);

/* Normally canBeDisabled returns YES and is implemented that way in the abstract NSInputServer class.
*/
- (BOOL) canBeDisabled NS_DEPRECATED_MAC(10_0, 10_6);

/* Many existing input servers have built-in key bindings that affect what happens within the marked region.  If such an input server wants to handle ALL key events through insertText:client:conversation: and never receive doCommandBySelector:client:conversation:, then it should respond (consistently) YES to this method.  The default is NO.  The processing of incoming events looks at this flag as reflected in the corresponding NSInputManager, before deciding how to deal with events.  A module which responds YES to this method must be prepared to deal with arbitrary strings of Unicode characters under all circumstances whenever it is active.
*/
- (BOOL) wantsToInterpretAllKeystrokes NS_DEPRECATED_MAC(10_0, 10_6);

/* Input servers that wants to receive mouse notifications should return YES & implement NSInputServerMouseTrackers protocol */
- (BOOL) wantsToHandleMouseEvents NS_DEPRECATED_MAC(10_0, 10_6);

/* This should return YES when the input method (language) prefers to delay text change notification 'till the input is actually committed.
*/
- (BOOL) wantsToDelayTextChangeNotifications NS_DEPRECATED_MAC(10_0, 10_6);

/* These methods are sent by current input manager when the application changes state so that the server can update its concept of who's current.  The actually "active" sender is the last one to have sent a senderDidBecomeActive: message.  They may not arrive in the expected order.
*/
- (void) inputClientBecomeActive:(nullable id)sender NS_DEPRECATED_MAC(10_0, 10_6);
- (void) inputClientResignActive:(nullable id)sender NS_DEPRECATED_MAC(10_0, 10_6);

/* These methods are sent by current input manger when it's enabled & the server returns YES to canBeDisabled.  When disabled, the server is expected to send only insertText: or doCommandBySelector:.
*/
- (void) inputClientEnabled:(nullable id)sender NS_DEPRECATED_MAC(10_0, 10_6);
- (void) inputClientDisabled:(nullable id)sender NS_DEPRECATED_MAC(10_0, 10_6);

/* These methods are sent by input manager when the conversation within a particular sender changes.
*/
- (void) activeConversationWillChange:(null_unspecified id)sender fromOldConversation:(NSInteger)oldConversation NS_DEPRECATED_MAC(10_0, 10_6);
- (void) activeConversationChanged:(null_unspecified id)sender toNewConversation:(NSInteger)newConversation NS_DEPRECATED_MAC(10_0, 10_6);

@end

/* These methods are sent to input servers that return YES to wantsToHandleMouseEvents.  thePoint is in screen coordinate.
*/
@protocol NSInputServerMouseTracker
- (BOOL) mouseDownOnCharacterIndex:(NSUInteger)theIndex atCoordinate:(NSPoint)thePoint withModifier:(NSUInteger)theFlags client:(null_unspecified id)sender NS_DEPRECATED_MAC(10_0, 10_6);
- (BOOL) mouseDraggedOnCharacterIndex:(NSUInteger)theIndex atCoordinate:(NSPoint)thePoint withModifier:(NSUInteger)theFlags client:(null_unspecified id)sender NS_DEPRECATED_MAC(10_0, 10_6);
- (void) mouseUpOnCharacterIndex:(NSUInteger)theIndex atCoordinate:(NSPoint)thePoint withModifier:(NSUInteger)theFlags client:(null_unspecified id)sender NS_DEPRECATED_MAC(10_0, 10_6);
@end

NS_CLASS_DEPRECATED_MAC(10_0, 10_6)
@interface NSInputServer : NSObject <NSInputServiceProvider, NSInputServerMouseTracker> {
    NSString *_name;
    id _delegate;
}

- initWithDelegate:(null_unspecified id)aDelegate name:(null_unspecified NSString *)name NS_DEPRECATED_MAC(10_0, 10_6);
@end

NS_ASSUME_NONNULL_END
