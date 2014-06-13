package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class can001confc_template
{
  protected static String nl;
  public static synchronized can001confc_template create(String lineSeparator)
  {
    nl = lineSeparator;
    can001confc_template result = new can001confc_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = "/*CODE_BLOCK_BEGIN[CAN001_Conf.c]*/" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2014, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without** " + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series   \t\t\t                          **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : App Developer                                                   **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/**" + NL + " * @file CAN001_Conf.c" + NL + " *" + NL + " * @App Version CAN001 <";
  protected final String TEXT_2 = "> " + NL + " * @brief  CAN001 App Handle definition based on UI selection." + NL + " *" + NL + " */" + NL + "#include <DAVE3.h>";
  protected final String TEXT_3 = NL;
  protected final String TEXT_4 = NL + "/* Node";
  protected final String TEXT_5 = " Handle structure */" + NL + "const CAN001_HandleType CAN001_Handle";
  protected final String TEXT_6 = " =" + NL + "{";
  protected final String TEXT_7 = NL + "\t.BaudRate = {0x";
  protected final String TEXT_8 = ", /* Baud rate Prescaler value */" + NL + "\t             0x";
  protected final String TEXT_9 = ", /* Synchronization Jump Width */" + NL + "\t             0x";
  protected final String TEXT_10 = ", /* Time segment 1 */" + NL + "\t             0x";
  protected final String TEXT_11 = ", /* Time segment 2 */" + NL + "\t             ";
  protected final String TEXT_12 = ",  /* Divide prescaler by 8 */" + NL + "\t             }," + NL + "\t.CanNodeRegs = CAN_NODE";
  protected final String TEXT_13 = ", /* Node register offset value */" + NL + "\t.NodeID = ";
  protected final String TEXT_14 = ",              /* Current node number */" + NL + "\t.LoopBackModeEn = ";
  protected final String TEXT_15 = ", /* Loop back mode selection*/" + NL + "\t.NodeMONo = ";
  protected final String TEXT_16 = ", /* Total message object allocated to node list */";
  protected final String TEXT_17 = "   " + NL + "\t.FirstMOMapping = ";
  protected final String TEXT_18 = NL + "};";
  protected final String TEXT_19 = NL + "// NODE IS NOT MAPPED";
  protected final String TEXT_20 = NL;
  protected final String TEXT_21 = NL + "/* Node";
  protected final String TEXT_22 = " LMO";
  protected final String TEXT_23 = " handle structure */" + NL + "CAN001_MessageHandleType CAN001_MessageHandle";
  protected final String TEXT_24 = "_";
  protected final String TEXT_25 = " =" + NL + "{";
  protected final String TEXT_26 = NL + "  \t.Identifier = 0x";
  protected final String TEXT_27 = ",  /* Message identifier mask */";
  protected final String TEXT_28 = NL + "  \t.Identifier = 0x";
  protected final String TEXT_29 = ",";
  protected final String TEXT_30 = "\t";
  protected final String TEXT_31 = NL + "\t.IDMask = 0x";
  protected final String TEXT_32 = ",";
  protected final String TEXT_33 = NL + "\t";
  protected final String TEXT_34 = NL + "  \t.IDMask = 0x";
  protected final String TEXT_35 = ",  /* Message identifier mask */" + NL + "\t";
  protected final String TEXT_36 = NL + "\t";
  protected final String TEXT_37 = NL + "  \t.IDMask = 0x";
  protected final String TEXT_38 = "," + NL + "\t";
  protected final String TEXT_39 = "\t" + NL + "\t.IDEMask = ";
  protected final String TEXT_40 = ",\t" + NL + "\t.IDExten = ";
  protected final String TEXT_41 = ", /* Message identifier Type */" + NL + "\t.DataLength = 0," + NL + "\t.MsgObjEN = CAN001_ENABLE," + NL + "\t.MsgObjType = (CAN_MsgType)";
  protected final String TEXT_42 = NL + "};";
  protected final String TEXT_43 = NL + "// MESSAGE";
  protected final String TEXT_44 = " IS NOT MAPPED";
  protected final String TEXT_45 = NL;
  protected final String TEXT_46 = NL;
  protected final String TEXT_47 = NL + NL + NL + "/*CODE_BLOCK_END*/ " + NL;
  protected final String TEXT_48 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
     String AppBaseuri = "app/can001/";
    stringBuffer.append(TEXT_1);
    stringBuffer.append( app.getAppVersion(AppBaseuri));
    stringBuffer.append(TEXT_2);
     String MappedUri = null; 
     String MappedUriMo = null; 
     String appInst  = null; 
     String nodeInst = null; 
     String moInst = null; 
     String CanMOuri = "peripheral/can/0/mo/"; 
     String appInst1  = null; 
    stringBuffer.append(TEXT_3);
     ArrayList<String> appsList = (ArrayList<String>)(app.getApps("app/can001/"));
 for (String appIns : appsList ) {
 appInst = appIns.substring(appIns.lastIndexOf("/")+1);
     MappedUri = app.getMappedUri(AppBaseuri + appInst + "/node"); 
     if((MappedUri != null) && (MappedUri != "")) { 
     nodeInst = MappedUri.substring(MappedUri.lastIndexOf("/")+1).trim(); 
    stringBuffer.append(TEXT_4);
    stringBuffer.append( nodeInst);
    stringBuffer.append(TEXT_5);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_6);
     int brp = app.getIntegerValue(AppBaseuri + appInst + "/can001_ironodebaudpre"); 
    stringBuffer.append(TEXT_7);
    stringBuffer.append( Integer.toHexString(brp) );
    stringBuffer.append(TEXT_8);
    stringBuffer.append( app.getHexValue(AppBaseuri + appInst + "/node/nbtr/sjw") );
    stringBuffer.append(TEXT_9);
    stringBuffer.append( app.getHexValue(AppBaseuri + appInst + "/node/nbtr/tseg1") );
    stringBuffer.append(TEXT_10);
    stringBuffer.append( app.getHexValue(AppBaseuri + appInst + "/node/nbtr/tseg2") );
    stringBuffer.append(TEXT_11);
    stringBuffer.append( app.getHexValue(AppBaseuri + appInst + "/node/nbtr/div8") );
    stringBuffer.append(TEXT_12);
    stringBuffer.append( nodeInst);
    stringBuffer.append(TEXT_13);
    stringBuffer.append( nodeInst);
    stringBuffer.append(TEXT_14);
    stringBuffer.append( app.getHexValue(AppBaseuri + appInst + "/node/npcr/lbm") );
    stringBuffer.append(TEXT_15);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst + "/can001_irwnodenomsgobjs") );
    stringBuffer.append(TEXT_16);
     MappedUriMo = app.getMappedUri(AppBaseuri + appInst +"/message1"); 
     moInst = MappedUriMo.substring(MappedUriMo.lastIndexOf("/")+1).trim(); 
    stringBuffer.append(TEXT_17);
    stringBuffer.append( moInst);
    stringBuffer.append(TEXT_18);
     } 
     else { 
    stringBuffer.append(TEXT_19);
     } 
    stringBuffer.append(TEXT_20);
     int mono = app.getIntegerValue(AppBaseuri + appInst + "/can001_irwnodenomsgobjs"); 
     for (int Msg=1; Msg<=mono; Msg++) { 
     MappedUri = app.getMappedUri(AppBaseuri + appInst +"/message" + Msg + "/mofcr"); 
     if((MappedUri != null) && (MappedUri != "")) { 
    stringBuffer.append(TEXT_21);
    stringBuffer.append( nodeInst);
    stringBuffer.append(TEXT_22);
    stringBuffer.append(Msg );
    stringBuffer.append(TEXT_23);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_24);
    stringBuffer.append(Msg );
    stringBuffer.append(TEXT_25);
     int idextval = app.getIntegerValue(AppBaseuri + appInst +"/message" + Msg + "/moar/ide"); 
     int idextval4 = app.getIntegerValue(AppBaseuri + appInst +"/message" + Msg + "/moar/id"); 
     if (idextval == 1) {
    stringBuffer.append(TEXT_26);
    stringBuffer.append( app.getHexValue(AppBaseuri + appInst +"/message" + Msg + "/moar/id") );
    stringBuffer.append(TEXT_27);
    } else {
     int idextval5 = idextval4>>18; 
    stringBuffer.append(TEXT_28);
    stringBuffer.append( Integer.toHexString(idextval5) );
    stringBuffer.append(TEXT_29);
    }
    stringBuffer.append(TEXT_30);
     int idextval2 = app.getIntegerValue(AppBaseuri + appInst +"/message" + Msg + "/moamr/am"); 
     int idemask = app.getIntegerValue(AppBaseuri + appInst +"/message" + Msg + "/moamr/mide"); 
     if (idemask == 0) {
    stringBuffer.append(TEXT_31);
    stringBuffer.append( app.getHexValue(AppBaseuri + appInst +"/message" + Msg + "/moamr/am") );
    stringBuffer.append(TEXT_32);
    } else {
    stringBuffer.append(TEXT_33);
     if (idextval == 1) {
    stringBuffer.append(TEXT_34);
    stringBuffer.append( app.getHexValue(AppBaseuri + appInst +"/message" + Msg + "/moamr/am") );
    stringBuffer.append(TEXT_35);
    } else {
    stringBuffer.append(TEXT_36);
     int idextval3 = idextval2>>18; 
    stringBuffer.append(TEXT_37);
    stringBuffer.append( Integer.toHexString(idextval3) );
    stringBuffer.append(TEXT_38);
    }
    }
    stringBuffer.append(TEXT_39);
    stringBuffer.append(idemask);
    stringBuffer.append(TEXT_40);
    stringBuffer.append( app.getHexValue(AppBaseuri + appInst +"/message" + Msg + "/moar/ide") );
    stringBuffer.append(TEXT_41);
    stringBuffer.append( app.getHexValue(AppBaseuri + appInst +"/message" + Msg + "/mostat/dir") );
    stringBuffer.append(TEXT_42);
     } 
     else { 
    stringBuffer.append(TEXT_43);
    stringBuffer.append(Msg);
    stringBuffer.append(TEXT_44);
     } 
    stringBuffer.append(TEXT_45);
    } 
    stringBuffer.append(TEXT_46);
    } 
    stringBuffer.append(TEXT_47);
    stringBuffer.append(TEXT_48);
    return stringBuffer.toString();
  }
}
