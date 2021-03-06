/**
 * Copyright (c) 2013, Tom Diggle
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, TDNotificationMode) {
    TDNotificationModeActivityIndicator,
    TDNotificationModeProgressBar,
    TDNotificationModeText
};

typedef NS_ENUM(NSInteger, TDNotificationType) {
    TDNotificationTypeError,
    TDNotificationTypeMessage,
    TDNotificationTypeSuccess,
    TDNotificationTypeActivity
};

typedef NS_ENUM(NSInteger, TDNotificationLocation) {
    TDNotificationLocationTop,
    TDNotificationLocationTopUnderNavigationBar,
    TDNotificationLocationTopAboveNavigationBar,
    TDNotificationLocationBottom,
    TDNotificationLocationBottomUnderToolbar,
    TDNotificationLocationBottomAboveToolbar
};

/** 
 * Displays a simple notification which can contain a title, subtitle, icon, progress bar or activity indicator.
 *
 * The notification will appear at the top of a view directly beneath any status or navigation bars.
 */

@interface TDNotificationPanel : UIView

/**
 * The notification type that will be used to determine the color of the background & type of icon displayed.
 *
 * @see TDNotificationType
 */
@property (nonatomic, assign) TDNotificationType notificationType;

/**
 * The notification operation mode. When using TDNotificationModeActivityIndicator or TDNotificationModeProgressBar the notification mode TDNotificationTypeMessage will be used.
 *
 * @see TDNotificationMode
 */
@property (nonatomic, assign) TDNotificationMode notificationMode;

/**
 *  The location for the notification to appear on the screen, relative to the view(controller) provided
 *
 *  @see TDNotificationLocation
 */
@property (nonatomic, assign) TDNotificationLocation notificationLocation;

// TODO: Which one works better?
// @property (nonatomic, strong) UIImage *backgroundImage;
// @property (nonatomic, strong) UIImageView *backgroundImageView;

/**
 * A short message to be displayed. If the text is too long it will get clipped by displaying "..." at the end. If set to nil no title is displayed.
 */
@property (nonatomic, copy) NSString *titleText;

/**
 * Font to be used for the title. Default is system bold font.
 */
@property (nonatomic, copy) UIFont *titleFont;

/**
 * A message to be displayed underneath the title. If set to nil no subtitle is displayed.
 */
@property (nonatomic, copy) NSString *subtitleText;

/**
 * Font to be use for the subtitle. Default is system font.
 */
@property (nonatomic, copy) UIFont *subtitleFont;

/**
 * The duration of the notification. Default is 0.
 */
@property (nonatomic, assign) NSTimeInterval notificationDuration;

/**
 * The completion handler to call when the notification duration expires
 */
@property (nonatomic, copy) void(^completionHandler)();

/**
 *  The block to be called when the notification is dismissed by the user
 */
@property (nonatomic, copy) void(^dismissBlock)();

/**
 *  The block to be called when the notification is touched by the user
 */
@property (nonatomic, copy) void(^touchBlock)();

/**
 * The progress of the progress bar, from 0.0 to 1.0. Defaults to 0.0.
 *
 * @see notificationMode
 */
@property (nonatomic, assign) float progress;

/**
 * YES notification will be dismissible when tapped, NO notification will not be dismissible when tapped.
 */
@property (nonatomic, assign, getter = isDismissible) BOOL dismissible;

/**
 *  YES if the notification should take the status bar height into consideration, else NO
 */
@property (nonatomic, assign) BOOL showUnderStatusBar;

// TODO: Replace all instances of "InView:(UIView*)view" with "InViewController:(UIViewController*)viewController"

// TODO: Add TDNotificationLocation to the initializers

+ (instancetype)showNotificationInView:(UIView *)view title:(NSString *)title subtitle:(NSString *)subtitle type:(TDNotificationType)type mode:(TDNotificationMode)mode dismissible:(BOOL)dismissible __attribute__((deprecated));

+ (instancetype)showNotificationInViewController:(UIViewController*)viewController title:(NSString *)title subtitle:(NSString *)subtitle type:(TDNotificationType)type mode:(TDNotificationMode)mode dismissible:(BOOL)dismissible;

+ (instancetype)showNotificationInView:(UIView *)view title:(NSString *)title subtitle:(NSString *)subtitle type:(TDNotificationType)type mode:(TDNotificationMode)mode dismissible:(BOOL)dismissible completionHandler:(void (^)())completionHandler __attribute__((deprecated));

+ (instancetype)showNotificationInViewController:(UIViewController *)viewController title:(NSString *)title subtitle:(NSString *)subtitle type:(TDNotificationType)type mode:(TDNotificationMode)mode dismissible:(BOOL)dismissible completionHandler:(void (^)())completionHandler;

+ (instancetype)showNotificationInView:(UIView *)view title:(NSString *)title subtitle:(NSString *)subtitle type:(TDNotificationType)type mode:(TDNotificationMode)mode dismissible:(BOOL)dismissible hideAfterDelay:(NSTimeInterval)delay __attribute__((deprecated));

+ (instancetype)showNotificationInViewController:(UIViewController *)view title:(NSString *)title subtitle:(NSString *)subtitle type:(TDNotificationType)type mode:(TDNotificationMode)mode dismissible:(BOOL)dismissible hideAfterDelay:(NSTimeInterval)delay;

+ (instancetype)showNotificationInView:(UIView *)view title:(NSString *)title subtitle:(NSString *)subtitle type:(TDNotificationType)type mode:(TDNotificationMode)mode dismissible:(BOOL)dismissible hideAfterDelay:(NSTimeInterval)delay completionHandler:(void (^)())completionHandler __attribute__((deprecated));

+ (instancetype)showNotificationInView:(UIView*)view title:(NSString*)title subtitle:(NSString*)subtitle type:(TDNotificationType)type mode:(TDNotificationMode)mode showUnderStatusBar:(BOOL)underStatusBar dismissible:(BOOL)dismissible dismissBlock:(void (^)())dismissBlock hideAfterDelay:(NSTimeInterval)delay completionHandler:(void (^)())completionHandler;

+ (BOOL)hideNotificationInView:(UIView *)view;

+ (NSArray *)notificationsInView:(UIView *)view;

#pragma mark - Instance Methods

- (instancetype)initWithView:(UIView *)view title:(NSString *)title subtitle:(NSString *)subtitle type:(TDNotificationType)type mode:(TDNotificationMode)mode showUnderStatusBar:(BOOL)underStatusBar dismissible:(BOOL)dismissible;
- (instancetype)initWithView:(UIView *)view title:(NSString *)title subtitle:(NSString *)subtitle type:(TDNotificationType)type mode:(TDNotificationMode)mode location:(TDNotificationLocation)location showUnderStatusBar:(BOOL)underStatusBar dismissible:(BOOL)dismissible;

- (void)show;

- (void)hide;

@end
