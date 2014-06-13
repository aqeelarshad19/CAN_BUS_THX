package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class can001confh_template
{
  protected static String nl;
  public static synchronized can001confh_template create(String lineSeparator)
  {
    nl = lineSeparator;
    can001confh_template result = new can001confh_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = "";
  protected final String TEXT_2 = NL + "/*CODE_BLOCK_BEGIN[CAN001_Conf.h]*/" + NL + "/**************************************************************************//**" + NL + " *" + NL + " * Copyright (C) 2014 Infineon Technologies AG. All rights reserved." + NL + " *" + NL + " * Infineon Technologies AG (Infineon) is supplying this software for use with " + NL + " * Infineon's microcontrollers.  " + NL + " * This file can be freely distributed within development tools that are " + NL + " * supporting such microcontrollers. " + NL + " *" + NL + " * THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED" + NL + " * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF" + NL + " * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE." + NL + " * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, " + NL + " * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER." + NL + " *" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series   \t\t\t                          **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : App Developer                                                   **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/**" + NL + " * @file CAN001_Conf.h" + NL + " * " + NL + " * @App Version CAN001 <";
  protected final String TEXT_3 = "> " + NL + " * @brief  CAN001 App Handle declaration based on UI selection." + NL + " *" + NL + " */" + NL + " " + NL + " #ifndef CONF_CAN001_H_" + NL + " #define CONF_CAN001_H_" + NL + " " + NL + "/* Support for C++ codebase */" + NL + "#ifdef __cplusplus" + NL + "extern \"C\" {" + NL + "#endif " + NL + "" + NL + "#include <DAVE3.h>";
  protected final String TEXT_4 = NL;
  protected final String TEXT_5 = NL + "extern const CAN001_HandleType CAN001_Handle";
  protected final String TEXT_6 = ";";
  protected final String TEXT_7 = NL + " // NODE IS NOT MAPPED";
  protected final String TEXT_8 = NL + "extern CAN001_MessageHandleType CAN001_MessageHandle";
  protected final String TEXT_9 = "_";
  protected final String TEXT_10 = ";";
  protected final String TEXT_11 = NL + " // MESSAGE";
  protected final String TEXT_12 = " IS NOT MAPPED";
  protected final String TEXT_13 = "               ";
  protected final String TEXT_14 = NL;
  protected final String TEXT_15 = NL + NL + "/* Macro to enable node";
  protected final String TEXT_16 = " initialisation exit macro */" + NL + "#define CAN_NODE";
  protected final String TEXT_17 = "_ENABLE" + NL + "/* Macro to access node";
  protected final String TEXT_18 = " registers */" + NL + "#define CAN001_Handle";
  protected final String TEXT_19 = "_NODE   CAN_NODE";
  protected final String TEXT_20 = NL + "// NODE IS NOT MAPPED";
  protected final String TEXT_21 = NL + "/* Macro to access Node";
  protected final String TEXT_22 = " LMO";
  protected final String TEXT_23 = " register */" + NL + "#define CAN001_Handle";
  protected final String TEXT_24 = "_NODE_LMO";
  protected final String TEXT_25 = " CAN_MO";
  protected final String TEXT_26 = " ";
  protected final String TEXT_27 = NL + "// MESSAGE";
  protected final String TEXT_28 = " IS NOT MAPPED";
  protected final String TEXT_29 = NL + NL + "/* Support for C++ codebase */" + NL + "#ifdef __cplusplus" + NL + "}" + NL + "#endif " + NL + "" + NL + "#endif" + NL + "" + NL + "/*CODE_BLOCK_END*/ " + NL;
  protected final String TEXT_30 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/can001/";
    stringBuffer.append(TEXT_2);
    stringBuffer.append( app.getAppVersion(AppBaseuri));
    stringBuffer.append(TEXT_3);
     String MappedUri = null; 
     String appInst  = null; 
     String nodeInst = null; 
     String moInst = null; 
     String CanMOuri = "peripheral/can/0/mo/"; 
    stringBuffer.append(TEXT_4);
     ArrayList<String> appsList = (ArrayList<String>)(app.getApps("app/can001/"));
 for (String appIns : appsList ) {
 appInst = appIns.substring(appIns.lastIndexOf("/")+1);
     MappedUri = app.getMappedUri(AppBaseuri + appInst + "/node"); 
     if((MappedUri != null) && (MappedUri != "")) { 
     nodeInst = MappedUri.substring(MappedUri.lastIndexOf("/")+1).trim(); 
    stringBuffer.append(TEXT_5);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_6);
     } 
     else { 
    stringBuffer.append(TEXT_7);
     } 
     int mono = app.getIntegerValue(AppBaseuri + appInst + "/can001_irwnodenomsgobjs"); 
     for (int Msg=1; Msg<=mono; Msg++) { 
     MappedUri = app.getMappedUri(AppBaseuri + appInst +"/message" + Msg + "/mofcr"); 
     if((MappedUri != null) && (MappedUri != "")) { 
    stringBuffer.append(TEXT_8);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_9);
    stringBuffer.append(Msg );
    stringBuffer.append(TEXT_10);
     } 
     else { 
    stringBuffer.append(TEXT_11);
    stringBuffer.append(Msg);
    stringBuffer.append(TEXT_12);
    }
    } 
    stringBuffer.append(TEXT_13);
    }
    stringBuffer.append(TEXT_14);
     for (String appIns : appsList ) {
 appInst = appIns.substring(appIns.lastIndexOf("/")+1);
     MappedUri = app.getMappedUri(AppBaseuri + appInst + "/node"); 
     if((MappedUri != null) && (MappedUri != "")) { 
     nodeInst = MappedUri.substring(MappedUri.lastIndexOf("/")+1).trim(); 
    stringBuffer.append(TEXT_15);
    stringBuffer.append( nodeInst);
    stringBuffer.append(TEXT_16);
    stringBuffer.append( nodeInst);
    stringBuffer.append(TEXT_17);
    stringBuffer.append( nodeInst);
    stringBuffer.append(TEXT_18);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_19);
    stringBuffer.append( nodeInst);
     } 
     else { 
    stringBuffer.append(TEXT_20);
     } 
     int mono = app.getIntegerValue(AppBaseuri + appInst + "/can001_irwnodenomsgobjs"); 
     for (int Msg=1; Msg<=mono; Msg++) { 
     MappedUri = app.getMappedUri(AppBaseuri + appInst +"/message" + Msg); 
     if((MappedUri != null) && (MappedUri != "")) { 
     moInst = MappedUri.substring(MappedUri.lastIndexOf("/")+1).trim(); 
    stringBuffer.append(TEXT_21);
    stringBuffer.append( nodeInst);
    stringBuffer.append(TEXT_22);
    stringBuffer.append(Msg );
    stringBuffer.append(TEXT_23);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_24);
    stringBuffer.append(Msg );
    stringBuffer.append(TEXT_25);
    stringBuffer.append( moInst);
    stringBuffer.append(TEXT_26);
     } 
     else { 
    stringBuffer.append(TEXT_27);
    stringBuffer.append(Msg);
    stringBuffer.append(TEXT_28);
     } 
    } 
    } 
    stringBuffer.append(TEXT_29);
    stringBuffer.append(TEXT_30);
    return stringBuffer.toString();
  }
}
