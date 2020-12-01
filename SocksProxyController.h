#import <UIKit/UIKit.h>
#import "SocksProxy.h"
#import "HTTPServer.h"
#include "ttdnsd.h"
//Max concurrent coonections
#define MAX_CONNECTIONS 100

@class MOGlassButton;

@interface SocksProxyController : UITableViewController <SocksProxyDelegate, NSNetServiceDelegate>
{
    MOGlassButton *                  _startOrStopButton;

    NSNetService *              _netService;
    CFSocketRef                 _listeningSocket;
	
	NSInteger				_nConnections;
	IBOutlet UITableView * proxyTableView;
	
@private
	NSString *currentStatusText;
    NSInteger currentPort;
    NSString *currentAddress;
    NSInteger currentOpenConnections;
    NSInteger currentConnectionCount;
    DNSServer * _DNSServer;
    HTTPServer * _HTTPServer;
    
}

@property (nonatomic, copy) NSString *currentStatusText;
@property (nonatomic, copy) NSString *httpAutoProxyURL;
@property (nonatomic, assign) NSInteger currentPort;
@property (nonatomic, copy) NSString *currentAddress;
@property (nonatomic, assign) NSInteger currentOpenConnections;
@property (nonatomic, assign) NSInteger currentConnectionCount;
@property (nonatomic, assign) NSInteger uploadData;
@property (nonatomic, assign) NSInteger downloadData;
@property (nonatomic, strong) IBOutlet MOGlassButton *                  startOrStopButton;

- (IBAction)startOrStopAction:(id)sender;

- (void)refreshProxyTable;
@end
