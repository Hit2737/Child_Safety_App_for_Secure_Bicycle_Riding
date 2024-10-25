#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#define MW_MULTI_TASKING_MODE 0

#define MW_USECODERTARGET 1
#define MW_TARGETHARDWARE Android Device (64bit)
#define MW_CONNECTIONINFO_TCPIP_IPADDRESS codertarget.android.internal.getDeviceIPAddressParameter
#define MW_CONNECTIONINFO_TCPIP_PORT 17725
#define MW_CONNECTIONINFO_TCPIP_VERBOSE 0
#define MW_EXTMODE_CONFIGURATION TCP/IP
#define MW_RTOS Android
#define MW_RTOSBASERATETASKPRIORITY 40
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_RUNTIME_BUILDACTION 1
#define MW_PACKAGE_NAME com.example
#define MW_APPOPTIONS_ENABLEALGORITHMEXPORT 0
#define MW_APPOPTIONS_ENABLE64BITBUILD 0
#define MW_THINGSPEAK_ENABLECUSTOMSERVER 48
#define MW_THINGSPEAK_IPADDRESS api.thingspeak.com
#define MW_THINGSPEAK_PORT 80
#define MW_SERIAL_SERIAL0_BAUD_RATE 3
#define MW_DASHBOARDPARAMETERS_ENABLECUSTOMDASHBOARDBLOCK 0
#define MW_DASHBOARDPARAMETERS_IPADDRESSTYPE 0
#define MW_DASHBOARDPARAMETERS_WEBSOCKETPORT 8000
#define MW_DASHBOARDPARAMETERS_HTTPPORT 8888
#define MW_UI_SCALEORSCROLL 0
#define MW_SIMULINKIO_TRANSPORTLAYERTYPE 0
#define MW_SIMULINKIO_MODELTRANSPORTDATAFCN codertarget.android.ioclient.getModelTransportInfo
#define MW_SIMULINKIO_SERVERDEPLOYFCN codertarget.android.ioclient.deployServer
#define MW_SIMULINKIO_SERVERSTOPFCN codertarget.android.ioclient.stopServer
#define MW_MQTT_BROKERSERVICE 0
#define MW_MQTT_BROKERADDRESS ssl://mqtt3.thingspeak.com
#define MW_MQTT_BROKERPORT 8883
#define MW_MQTT_USERNAME 
#define MW_MQTT_PASSWORD 
#define MW_MQTT_CLIENTID 
#define MW_DATAVERSION 2016.02
#define MW_DASHBOARDCODEGENINFO_ENABLECODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CIRCULARGAUGE_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CIRCULARGAUGE_BLOCKCLASS codertarget.internal.androidCircularGauge
#define MW_DASHBOARDCODEGENINFO_CIRCULARGAUGE_REGFCN codertarget.internal.androidRegisterDashboardBlk
#define MW_DASHBOARDCODEGENINFO_CIRCULARGAUGE_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_SEMICIRCULARGAUGE_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_SEMICIRCULARGAUGE_BLOCKCLASS codertarget.internal.androidSemiCircularGauge
#define MW_DASHBOARDCODEGENINFO_SEMICIRCULARGAUGE_REGFCN codertarget.internal.androidRegisterDashboardBlk
#define MW_DASHBOARDCODEGENINFO_SEMICIRCULARGAUGE_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_QUARTERGAUGE_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_QUARTERGAUGE_BLOCKCLASS codertarget.internal.androidQuarterGauge
#define MW_DASHBOARDCODEGENINFO_QUARTERGAUGE_REGFCN codertarget.internal.androidRegisterDashboardBlk
#define MW_DASHBOARDCODEGENINFO_QUARTERGAUGE_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_KNOB_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_KNOB_BLOCKCLASS codertarget.internal.androidKnob
#define MW_DASHBOARDCODEGENINFO_KNOB_REGFCN codertarget.internal.androidRegisterDashboardSourceBlock
#define MW_DASHBOARDCODEGENINFO_KNOB_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_SLIDERSWITCH_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_SLIDERSWITCH_BLOCKCLASS codertarget.internal.androidSliderSwitch
#define MW_DASHBOARDCODEGENINFO_SLIDERSWITCH_REGFCN codertarget.internal.androidRegisterDashboardSourceBlock
#define MW_DASHBOARDCODEGENINFO_SLIDERSWITCH_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_TOGGLESWITCH_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_TOGGLESWITCH_BLOCKCLASS codertarget.internal.androidToggleSwitch
#define MW_DASHBOARDCODEGENINFO_TOGGLESWITCH_REGFCN codertarget.internal.androidRegisterDashboardSourceBlock
#define MW_DASHBOARDCODEGENINFO_TOGGLESWITCH_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_ROCKERSWITCH_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_ROCKERSWITCH_BLOCKCLASS codertarget.internal.androidRockerSwitch
#define MW_DASHBOARDCODEGENINFO_ROCKERSWITCH_REGFCN codertarget.internal.androidRegisterDashboardSourceBlock
#define MW_DASHBOARDCODEGENINFO_ROCKERSWITCH_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_SLIDER_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_SLIDER_BLOCKCLASS codertarget.internal.androidDashboardSlider
#define MW_DASHBOARDCODEGENINFO_SLIDER_REGFCN codertarget.internal.androidRegisterDashboardSourceBlock
#define MW_DASHBOARDCODEGENINFO_SLIDER_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_LAMP_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_LAMP_BLOCKCLASS codertarget.internal.androidLamp
#define MW_DASHBOARDCODEGENINFO_LAMP_REGFCN codertarget.internal.androidRegisterDashboardBlk
#define MW_DASHBOARDCODEGENINFO_LAMP_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_DISPLAYBLOCK_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_DISPLAYBLOCK_BLOCKCLASS codertarget.internal.androidDashboardDisplay
#define MW_DASHBOARDCODEGENINFO_DISPLAYBLOCK_REGFCN codertarget.internal.androidRegisterDashboardBlk
#define MW_DASHBOARDCODEGENINFO_DISPLAYBLOCK_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_EDITFIELD_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_EDITFIELD_BLOCKCLASS codertarget.internal.androidDashboardEditField
#define MW_DASHBOARDCODEGENINFO_EDITFIELD_REGFCN codertarget.internal.androidRegisterDashboardSourceBlock
#define MW_DASHBOARDCODEGENINFO_EDITFIELD_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_PUSHBUTTON_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_PUSHBUTTON_BLOCKCLASS codertarget.internal.androidPushButtonBlock
#define MW_DASHBOARDCODEGENINFO_PUSHBUTTON_REGFCN codertarget.internal.androidRegisterDashboardSourceBlock
#define MW_DASHBOARDCODEGENINFO_PUSHBUTTON_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBCIRCULARGAUGE_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBCIRCULARGAUGE_BLOCKCLASS codertarget.internal.androidCustomWebCircularGauge
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBCIRCULARGAUGE_REGFCN codertarget.internal.androidRegisterDashboardBlk
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBCIRCULARGAUGE_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBKNOB_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBKNOB_BLOCKCLASS codertarget.internal.androidCustomWebKnob
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBKNOB_REGFCN codertarget.internal.androidRegisterDashboardSourceBlock
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBKNOB_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBSWITCH_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBSWITCH_BLOCKCLASS codertarget.internal.androidCustomWebHorizontalSlider
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBSWITCH_REGFCN codertarget.internal.androidRegisterDashboardSourceBlock
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBSWITCH_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBPUSHBUTTON_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBPUSHBUTTON_BLOCKCLASS codertarget.internal.androidCustomWebVerticalSlider
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBPUSHBUTTON_REGFCN codertarget.internal.androidRegisterDashboardSourceBlock
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBPUSHBUTTON_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALSLIDER_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALSLIDER_BLOCKCLASS codertarget.internal.androidCustomWebSwitch
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALSLIDER_REGFCN codertarget.internal.androidRegisterDashboardSourceBlock
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALSLIDER_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALSLIDER_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALSLIDER_BLOCKCLASS codertarget.internal.androidCustomWebPushButton
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALSLIDER_REGFCN codertarget.internal.androidRegisterDashboardSourceBlock
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALSLIDER_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALGAUGE_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALGAUGE_BLOCKCLASS codertarget.internal.androidCustomWebLamp
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALGAUGE_REGFCN codertarget.internal.androidRegisterDashboardBlk
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBHORIZONTALGAUGE_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALGAUGE_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALGAUGE_BLOCKCLASS codertarget.internal.androidCustomWebHorizontalGauge
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALGAUGE_REGFCN codertarget.internal.androidRegisterDashboardBlk
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBVERTICALGAUGE_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBLAMP_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBLAMP_BLOCKCLASS codertarget.internal.androidCustomWebVerticalGauge
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBLAMP_REGFCN codertarget.internal.androidRegisterDashboardBlk
#define MW_DASHBOARDCODEGENINFO_CUSTOMWEBLAMP_VALIDATEFCN codertarget.internal.androidIsDashboardBlockValidForCodegen

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif
