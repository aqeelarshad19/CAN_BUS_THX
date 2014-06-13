<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="CANGLOBAL" description="App for configuring CAN Clock." descriptionURL="/doc/html/group___c_a_n_g_l_o_b_a_l_app.html" mode="SHARABLE" URI="http://www.infineon.com/1.0.12/app/canglobal/0">
  <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../CAN001/1.0.12/can001_0.app#//@consumed.21"/>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="CAN Clock Divider " URI="http://www.infineon.com/1.0.12/app/canglobal/0/canglobal_erwcanclkdivider">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <toolTipHelpDescription>CAN Clock Divider mode settings</toolTipHelpDescription>
    <item name="Normal Divider" evalFunction="&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;function ForwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var value = SCM.getIntValue(currentResource);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = SCM.getResource(&quot;canglobal/fdr/dm&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if (value == 1 ) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(Res,1);&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;} else if (value == 0) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(Res,2);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;function BackwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = SCM.getResource(&quot;canglobal/fdr/dm&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var value = SCM.getIntValue(Res); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if (value == 1 ) { &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,1);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;} else if (value == -1 ){&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,1);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;else {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,0);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;" URI="http://www.infineon.com/1.0.12/app/canglobal/0/canglobal_erwcanclkdivider/0" downWardmappedList="//@consumed.5" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Select Normal Divider Mode(fcan = fpb * (1024 - FDR.STEP))</toolTipHelpDescription>
    </item>
    <item name="Fractional Divider" evalFunction="&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;function ForwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var value = SCM.getIntValue(currentResource);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = SCM.getResource(&quot;canglobal/fdr/dm&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if (value == 1 ) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(Res,2);&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;} else if (value == 0) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(Res,1);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;function BackwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = SCM.getResource(&quot;canglobal/fdr/dm&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var value = SCM.getIntValue(Res); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if (value == 2 ) { &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,1);&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;} else if (value == -1 ){&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,0);&#xD;&#xA;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;else {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,0);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;" URI="http://www.infineon.com/1.0.12/app/canglobal/0/canglobal_erwcanclkdivider/1" downWardmappedList="//@consumed.5" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Select Fractional Divider Mode(fcan = (fpb * FDR.STEP)/1024)</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Desired MultiCAN Frequency" description="" evalFunction="&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;function ForwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;var Res0 = SCM.getResource(&quot;clockapp/clk001_iroActualFreqPB&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;var clock = SCM.getIntValue(Res0); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;var Res1 = SCM.getResource(&quot;canglobal/fdr/dm&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;var dmvalue = SCM.getIntValue(Res1); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;var Res2 = SCM.getResource(&quot;canglobal/fdr/step&quot;);  &#xD;&#xA;                    var FreqEntered = SCM.getIntValue(currentResource);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;if (dmvalue == 1 ) {&#xD;&#xA;                         var step1 = (1024 - (clock/FreqEntered));&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9; SCM.setIntValue(Res2,step1);&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;} else if (dmvalue == 2) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var step2 = ((FreqEntered * 1024)/clock);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(Res2,step2);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;var tempRes = SCM.getResource(&quot;canglobal_DesFreqTemp&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(tempRes,FreqEntered);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;function BackwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;   var tempRes = SCM.getResource(&quot;canglobal_DesFreqTemp&quot;);&#xD;&#xA;                   var value = SCM.getIntValue(tempRes);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;   SCM.setIntValue(currentResource,value);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;}" URI="http://www.infineon.com/1.0.12/app/canglobal/0/canglobal_irwdesiredfreqcan" downWardmappedList="//@consumed.4 //@consumed.0" maxValue="78" minValue="0">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <localValue xsi:type="ResourceModel:StringValue" value="78"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <toolTipHelpDescription>Enter desired MultiCAN module frequency</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Actual MultiCAN Frequency" description="" evalFunction="&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;function ForwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;{ &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res0 = SCM.getResource(&quot;clockapp/clk001_iroActualFreqPB&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var clock = SCM.getIntValue(Res0); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res1 = SCM.getResource(&quot;canglobal/fdr/dm&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var dmvalue = SCM.getIntValue(Res1); &#xD;&#xA;                        var tempRes = SCM.getResource(&quot;canglobal_DesFreqTemp&quot;);&#xD;&#xA;                        var FreqEntered = SCM.getIntValue(tempRes);&#x9;&#xD;&#xA;              &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;function BackwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res0 = SCM.getResource(&quot;clockapp/clk001_iroActualFreqPB&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var clock = SCM.getIntValue(Res0); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res1 = SCM.getResource(&quot;canglobal/fdr/dm&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var dmvalue = SCM.getIntValue(Res1); &#xD;&#xA;                        var tempRes = SCM.getResource(&quot;canglobal_DesFreqTemp&quot;);&#xD;&#xA;                        var FreqEntered = SCM.getIntValue(tempRes);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if (dmvalue == 1 ) {&#xD;&#xA;                         &#x9;var step1 = Math.floor((1024 - (clock/FreqEntered)));&#xD;&#xA;                            var Freq1 = Math.floor((clock/(1024 - step1)));&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9; &#x9;SCM.setIntValue(currentResource,Freq1);&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;} else if (dmvalue == 2) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var step2 = Math.floor(((FreqEntered * 1024)/clock));&#xD;&#xA;                            var Freq2 = Math.floor(((clock * step2)/1024));&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,Freq2);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;" URI="http://www.infineon.com/1.0.12/app/canglobal/0/canglobal_iroactualfreqcan" maxValue="3FF" minValue="0">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../CAN001/1.0.12/can001_0.app#//@consumed.169"/>
    <localValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <toolTipHelpDescription>Actual MultiCAN module frequency</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Step Value" description="" evalFunction="&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;function ForwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;{ &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res0 = SCM.getResource(&quot;clockapp/clk001_iroActualFreqPB&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var clock = SCM.getIntValue(Res0); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res1 = SCM.getResource(&quot;canglobal/fdr/dm&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var dmvalue = SCM.getIntValue(Res1); &#xD;&#xA;                        var tempRes = SCM.getResource(&quot;canglobal_DesFreqTemp&quot;);&#xD;&#xA;                        var FreqEntered = SCM.getIntValue(tempRes);&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;function BackwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res0 = SCM.getResource(&quot;clockapp/clk001_iroActualFreqPB&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var clock = SCM.getIntValue(Res0); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res1 = SCM.getResource(&quot;canglobal/fdr/dm&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var dmvalue = SCM.getIntValue(Res1); &#xD;&#xA;                        var tempRes = SCM.getResource(&quot;canglobal_DesFreqTemp&quot;);&#xD;&#xA;                        var FreqEntered = SCM.getIntValue(tempRes);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if (dmvalue == 1 ) {&#xD;&#xA;                         &#x9;var step1 = (1024 - (clock/FreqEntered));&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9; &#x9;SCM.setIntValue(currentResource,step1);&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;} else if (dmvalue == 2) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var step2 = ((FreqEntered * 1024)/clock);&#xD;&#xA;                        if (step2 >= 1024 ) {&#xD;&#xA;                            var step3 = (step2 - 1);&#xD;&#xA;                            SCM.setIntValue(currentResource,step3);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;} else {&#xD;&#xA;                            SCM.setIntValue(currentResource,step2);&#xD;&#xA;                        }&#x9;&#x9;&#xD;&#xA;                        }&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;" URI="http://www.infineon.com/1.0.12/app/canglobal/0/canglobal_irwstepcan" maxValue="3FF" minValue="0">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="3FF"/>
    <localValue xsi:type="ResourceModel:StringValue" value="3FF"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="3ff"/>
    <toolTipHelpDescription>Step value for MCAN FDR Register</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Peripheral Clock" evalFunction="&#xD;&#xA;                        function ForwardMapping(){&#xD;&#xA;                        &#x9;&#xD;&#xA;                              var Res0 = SCM.getResource(&quot;clockapp/clk001_iroActualFreqPB&quot;);   &#xD;&#xA;                              var value0 = SCM.getIntValue(Res0);                   &#xD;&#xA;                        }&#xD;&#xA;                        function BackwardMapping(){                    &#x9;&#x9;&#xD;&#xA;                       &#x9;&#x9;var Res1 = SCM.getResource(&quot;clockapp/clk001_iroActualFreqPB&quot;); &#xD;&#xA;                       &#x9;&#x9;var value1 = SCM.getIntValue(Res1);     &#xD;&#xA;                    &#x9;&#x9;SCM.setIntValue(currentResource, value1);&#xD;&#xA;                        }&#xD;&#xA;                        " URI="http://www.infineon.com/1.0.12/app/canglobal/0/canglobal_iroclock" maxValue="1C200" minValue="0">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <localValue xsi:type="ResourceModel:StringValue" value="78"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <toolTipHelpDescription>Peripheral Clock Frequency</toolTipHelpDescription>
  </provided>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.12/app/canglobal/0/canglobal_desfreqtemp" upWardMappingList="//@provided.1 //@provided.2 //@provided.3" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.12/app/canglobal/0/canglobal">
    <downWardmappedList xsi:type="ResourceModel:ResourceGroup" href="../../CAN/CAN_0.dd#//@provided.24"/>
    <requiredResource uriString="peripheral/can/0/global" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.12/app/canglobal/0/resetapp">
    <downWardmappedList xsi:type="ResourceModel:App" href="../../RESET001/1.0.14/reset001_0.app#/"/>
    <requiredResource uriString="app/reset001/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.12/app/canglobal/0/clockapp">
    <downWardmappedList xsi:type="ResourceModel:App" href="../../CLK001/1.0.42/clk001_0.app#/"/>
    <requiredResource uriString="app/clk001/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.12/app/canglobal/0/canglobal/fdr/step" upWardMappingList="//@provided.1" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="400"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CAN/CAN_0.dd#//@provided.25"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="400"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.12/app/canglobal/0/canglobal/fdr/dm" upWardMappingList="//@provided.0/@item.0 //@provided.0/@item.1 //@provided.1 //@provided.2 //@provided.3" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CAN/CAN_0.dd#//@provided.26"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.12/app/canglobal/0/clockapp/clk001_iroactualfreqpb" upWardMappingList="//@provided.1 //@provided.2 //@provided.3 //@provided.4" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <downWardmappedList xsi:type="ResourceModel:IntegerParameter" href="../../CLK001/1.0.42/clk001_0.app#//@provided.42"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="78"/>
  </consumed>
  <propertyConstants name="uri_can" value="peripheral/can/0/">
    <propertyConstants name="uri_resetapp" value="app/reset001/">
      <propertyConstants name="uri_clockapp" value="app/clk001/"/>
    </propertyConstants>
  </propertyConstants>
  <categoryDescription description="Peripheral Specific Apps" name="Peripheral Specific Apps">
    <subCategory description="Communication" name="Communication">
      <subCategory description="Controller Area Network Controller (MultiCAN)" name="Controller Area Network Controller (MultiCAN)"/>
    </subCategory>
  </categoryDescription>
  <categoryDescription description="Basic Applications" name="Basic Applications">
    <subCategory description="Communication" name="Communication">
      <subCategory description="CAN" name="CAN"/>
    </subCategory>
  </categoryDescription>
  <manifestInfo version="1.0.12">
    <keywords>CANGLOBAL</keywords>
    <keywords>MultiCAN</keywords>
    <properties xsi:type="ResourceModel:AppProperties_1_0" initProvider="true" singleton="true"/>
  </manifestInfo>
  <datagenerate fileName="CANGLOBAL.h" fileType="HFILE" templateFileName="CANGLOBAL.hdt" templateEngine="NONE" fileAction="COPY"/>
  <datagenerate fileName="CANGLOBAL.c" templateFileName="CANGLOBALc.jet"/>
  <softwareIdList>45.0.1</softwareIdList>
  <softwareIdList>45.0.2</softwareIdList>
  <softwareIdList>45.0.3</softwareIdList>
  <softwareIdList>45.2.3</softwareIdList>
  <softwareIdList>45.0200.1</softwareIdList>
  <softwareIdList>45.0200.2</softwareIdList>
  <softwareIdList>45.0200.3</softwareIdList>
  <softwareIdList>45.0202.3</softwareIdList>
  <softwareIdList>44.0.3</softwareIdList>
  <softwareIdList>44.00.5</softwareIdList>
  <softwareIdList>44.02.3</softwareIdList>
  <softwareIdList>44.02.5</softwareIdList>
  <softwareIdList>42.00.5</softwareIdList>
  <softwareIdList>42.0.6</softwareIdList>
  <softwareIdList>42.0200.5</softwareIdList>
  <softwareIdList>42.0200.6</softwareIdList>
  <softwareIdList>42.0208.6</softwareIdList>
  <softwareIdList>44.0200.5</softwareIdList>
  <softwareIdList>44.0202.3</softwareIdList>
  <softwareIdList>44.0202.5</softwareIdList>
  <softwareIdList>44.0200.3</softwareIdList>
  <softwareIdList>45.0300.1</softwareIdList>
  <softwareIdList>45.0300.3</softwareIdList>
  <softwareIdList>45.0302.3</softwareIdList>
  <softwareIdList>45.0300.2</softwareIdList>
</ResourceModel:App>
