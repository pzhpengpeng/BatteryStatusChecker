//
//  BatteryInfoManager.h
//  TestTaskForSwTec
//
//  Created by Eugeny Ulyankin on 10/28/17.
//  Copyright © 2017 Eugeny. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DatabaseWrapper.h"
#import "BatteryInfo.h"

@interface BatteryInfoManager : NSObject <DatabaseWrapperDelegate>
+ (instancetype)sharedInstance;



- (void)addTotalBatteryInfoObserver:(id)object;
- (void)removeTotalBatteryInfoObserver:(id)object;
/**
 Using for sharing battery information between array and database
 @return serial dispatch queue
 */
+ (dispatch_queue_t)sharedQueue;

/**
 Get last battery and state to showing it for the first time
 */
- (void)timerHandle;

/**
 Loading history array from database
 */
- (void)loadHistory;

/**
 Runs the battery statistics with timer every 30 seconds
 */
- (void)startBatteryInfoMonitoring;

/**
 Invalidate the timer, which as described above
 */
- (void)stopBatteryInfoMonitoring;

/**
 Delete one element from the array and database
 @param batteryInfo object
 */
- (void)deleteBatteryInfo:(BatteryInfo *)batteryInfo;

/**
 Delete battery statistics some long time period ago.
 Can be used as a filter in the future
 @param someMinutesAgo means time range from now
 @param options should be emphasize the handling this type of update
 */
- (void)deleteBatteryInfoSomeMinutesAgo:(NSInteger)someMinutesAgo withOptions:(UpdateOptions)options;

/**
 Delete battery statistics in range
 @param itemIndex index from to delete
 @param options hould be emphasize the first or last items will be deleted
 */
- (void)deleteNitems:(NSInteger)itemIndex withOptions:(UpdateOptions)options;

@end
