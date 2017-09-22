// ======================================================================
// External_LCD_Display.v generated from TopDesign.cysch
// 05/18/2017 at 15:19
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_TMA4 2
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 3
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PSOC5TM 5
`define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1
`define CYDEV_CHIP_REV_PSOC5TM_ES1 1
`define CYDEV_CHIP_REV_PSOC5TM_ES0 0
`define CYDEV_CHIP_DIE_VOLANS 6
`define CYDEV_CHIP_REV_VOLANS_PRODUCTION 0
`define CYDEV_CHIP_DIE_BERRYPECKER 7
`define CYDEV_CHIP_REV_BERRYPECKER_PRODUCTION 0
`define CYDEV_CHIP_DIE_CRANE 8
`define CYDEV_CHIP_REV_CRANE_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM3 9
`define CYDEV_CHIP_REV_FM3_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM4 10
`define CYDEV_CHIP_REV_FM4_PRODUCTION 0
`define CYDEV_CHIP_DIE_EXPECT 4
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 4
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_FM0P 4
`define CYDEV_CHIP_FAMILY_FM3 5
`define CYDEV_CHIP_FAMILY_FM4 6
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_4G 2
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 3
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 4
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 5
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 6
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 7
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 8
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 9
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 10
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 11
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 12
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 13
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 14
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 15
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 16
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 17
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4C 18
`define CYDEV_CHIP_REVISION_4C_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_5B 19
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 20
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 21
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 22
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 23
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 24
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 25
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 19
`define CYDEV_CHIP_REVISION_USED 0
// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// Component: demux_v1_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10\demux_v1_10.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10\demux_v1_10.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// VDAC8_v1_90(Data_Source=0, Initial_Value=100, Strobe_Mode=1, VDAC_Range=0, VDAC_Speed=2, Voltage=400, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=VDAC8_v1_90, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SineWaveGen:VDAC8, CY_INSTANCE_SHORT_NAME=VDAC8, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=90, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=SineWaveGen_VDAC8, )
module VDAC8_v1_90_0 (
    strobe,
    data,
    vOut);
    input       strobe;
    input      [7:0] data;
    inout       vOut;
    electrical  vOut;

    parameter Data_Source = 0;
    parameter Initial_Value = 100;
    parameter Strobe_Mode = 1;

    electrical  Net_77;
          wire  Net_83;
          wire  Net_82;
          wire  Net_81;

    cy_psoc3_vidac8_v1_0 viDAC8 (
        .reset(Net_83),
        .idir(Net_81),
        .data(data[7:0]),
        .strobe(strobe),
        .vout(vOut),
        .iout(Net_77),
        .ioff(Net_82),
        .strobe_udb(strobe));
    defparam viDAC8.is_all_if_any = 0;
    defparam viDAC8.reg_data = 0;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_81));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_82));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_83));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_77));



endmodule

// OpAmp_v1_90(Mode=1, Power=2, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=OpAmp_v1_90, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SineWaveGen:BuffAmp, CY_INSTANCE_SHORT_NAME=BuffAmp, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=90, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=SineWaveGen_BuffAmp, )
module OpAmp_v1_90_1 (
    Vplus,
    Vout,
    Vminus);
    inout       Vplus;
    electrical  Vplus;
    inout       Vout;
    electrical  Vout;
    inout       Vminus;
    electrical  Vminus;

    parameter Mode = 1;

    electrical  Net_29;

    cy_psoc3_abuf_v1_0 ABuf (
        .vplus(Vplus),
        .vminus(Net_29),
        .vout(Vout));

	// abuf_negInput_mux (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 abuf_negInput_mux_connect(Net_29, Vout);
	defparam abuf_negInput_mux_connect.sig_width = 1;



endmodule

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// Component: cydff_v1_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30\cydff_v1_30.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30\cydff_v1_30.v"
`endif

// WaveDAC8_v2_10(Clock_SRC=0, DAC_Range=16, DacModeReplString=VDAC8, Sample_Clock_Freq=100000, Wave1_Amplitude=0.7, Wave1_Data=88u,93u,98u,104u,109u,115u,120u,125u,130u,134u,139u,143u,147u,151u,155u,158u,161u,164u,167u,169u,171u,172u,173u,174u,175u,175u,175u,174u,173u,172u,171u,169u,167u,164u,161u,158u,155u,151u,147u,143u,139u,134u,130u,125u,120u,115u,109u,104u,98u,93u,88u,82u,77u,71u,66u,60u,55u,50u,45u,41u,36u,32u,28u,24u,20u,17u,14u,11u,8u,6u,4u,3u,2u,1u,0u,0u,0u,1u,2u,3u,4u,6u,8u,11u,14u,17u,20u,24u,28u,32u,36u,41u,45u,50u,55u,60u,66u,71u,77u,82u, Wave1_DCOffset=0.35, Wave1_Length=100, Wave1_PhaseShift=0, Wave1_Type=0, Wave2_Amplitude=1, Wave2_Data=128u,132u,138u,143u,148u,152u,158u,162u,168u,172u,178u,182u,188u,192u,198u,202u,208u,213u,218u,222u,228u,232u,238u,242u,248u,252u,248u,242u,238u,232u,228u,222u,218u,212u,208u,202u,198u,192u,188u,182u,178u,173u,168u,162u,158u,152u,148u,143u,138u,132u,128u,122u,118u,112u,107u,102u,97u,93u,88u,83u,78u,73u,68u,62u,57u,52u,47u,42u,37u,33u,28u,23u,18u,13u,8u,3u,8u,13u,18u,23u,28u,33u,37u,42u,47u,52u,57u,62u,68u,73u,78u,83u,88u,93u,97u,102u,107u,112u,118u,122u, Wave2_DCOffset=0.51, Wave2_Length=100, Wave2_PhaseShift=0, Wave2_Type=2, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=WaveDAC8_v2_10, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SineWaveGen, CY_INSTANCE_SHORT_NAME=SineWaveGen, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=10, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=SineWaveGen, )
module WaveDAC8_v2_10_2 (
    Wave,
    ws,
    clock,
    wc1,
    wc2);
    inout       Wave;
    electrical  Wave;
    input       ws;
    input       clock;
    output      wc1;
    output      wc2;


          wire  Net_280;
    electrical  Net_273;
          wire  Net_202;
          wire  Net_201;
          wire [7:0] Net_171;
          wire [7:0] Net_170;
          wire  Net_339;
          wire  Net_341;
          wire  Net_153;
    electrical  Net_211;
          wire  Net_134;
          wire  Net_107;
          wire  Net_183;
          wire  Net_336;
          wire  Net_279;
          wire  Net_80;
    electrical  Net_247;
    electrical  Net_254;
    electrical  Net_256;
    electrical  Net_190;
    electrical  Net_189;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_211));

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_189, Net_256);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_190, Net_211);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_254));


	cy_dma_v1_0
		#(.drq_type(2'b10))
		Wave1_DMA
		 (.drq(Net_183),
		  .trq(1'b0),
		  .nrq(wc1));



	cy_dma_v1_0
		#(.drq_type(2'b10))
		Wave2_DMA
		 (.drq(Net_107),
		  .trq(1'b0),
		  .nrq(wc2));


    // -- De Mux start --
    if (1)
    begin : demux
        reg  tmp__demux_0_reg;
        reg  tmp__demux_1_reg;
        always @(Net_336 or Net_134)
        begin
            case (Net_134)
                1'b0:
                begin
                    tmp__demux_0_reg = Net_336;
                    tmp__demux_1_reg = 1'b0;
                end
                1'b1:
                begin
                    tmp__demux_0_reg = 1'b0;
                    tmp__demux_1_reg = Net_336;
                end
            endcase
        end
        assign Net_183 = tmp__demux_0_reg;
        assign Net_107 = tmp__demux_1_reg;
    end
    // -- De Mux end --

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_336 = clock;

    VDAC8_v1_90_0 VDAC8 (
        .strobe(Net_336),
        .data(8'b00000000),
        .vOut(Net_189));
    defparam VDAC8.Data_Source = 0;
    defparam VDAC8.Initial_Value = 100;
    defparam VDAC8.Strobe_Mode = 1;

    OpAmp_v1_90_1 BuffAmp (
        .Vplus(Net_256),
        .Vout(Net_247),
        .Vminus(Net_273));
    defparam BuffAmp.Mode = 1;

	// cy_analog_virtualmux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_3_connect(Wave, Net_247);
	defparam cy_analog_virtualmux_3_connect.sig_width = 1;


    assign Net_280 = Net_80 | Net_279;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_80));

    // -- DFF Start --
    reg  cydff_1;
    always @(posedge Net_336)
    begin
        cydff_1 <= ws;
    end
    assign Net_134 = cydff_1;
    // -- DFF End --



endmodule

// CharLCD_v2_20(ConversionRoutines=true, CUSTOM0=0,E,8,8,8,E,0, CUSTOM1=0,A,A,4,4,4,0, CUSTOM2=0,E,A,E,8,8,0, CUSTOM3=0,E,A,C,A,A,0, CUSTOM4=0,E,8,C,8,E,0, CUSTOM5=0,E,8,E,2,E,0, CUSTOM6=0,E,8,E,2,E,0, CUSTOM7=0,4,4,4,0,4,0, CustomCharacterSet=0, TypeReplacementString=uint8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=CharLCD_v2_20, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=LCD_Char_1, CY_INSTANCE_SHORT_NAME=LCD_Char_1, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=20, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=LCD_Char_1, )
module CharLCD_v2_20_3 ;



	wire [6:0] tmpOE__LCDPort_net;
	wire [6:0] tmpFB_6__LCDPort_net;
	wire [6:0] tmpIO_6__LCDPort_net;
	wire [0:0] tmpINTERRUPT_0__LCDPort_net;
	electrical [0:0] tmpSIOVREF__LCDPort_net;

	cy_psoc3_pins_v1_10
		#(.id("b1912798-7c8f-474f-b804-73d3f6cea2c2/ed092b9b-d398-4703-be89-cebf998501f6"),
		  .drive_mode(21'b110_110_110_110_110_110_110),
		  .ibuf_enabled(7'b1_1_1_1_1_1_1),
		  .init_dr_st(7'b0_0_0_0_0_0_0),
		  .input_clk_en(0),
		  .input_sync(7'b1_1_1_1_1_1_1),
		  .input_sync_mode(7'b0_0_0_0_0_0_0),
		  .intr_mode(14'b00_00_00_00_00_00_00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(",,,,,,"),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(7'b0_0_0_0_0_0_0),
		  .oe_reset(0),
		  .oe_sync(7'b0_0_0_0_0_0_0),
		  .output_clk_en(0),
		  .output_clock_mode(7'b0_0_0_0_0_0_0),
		  .output_conn(7'b0_0_0_0_0_0_0),
		  .output_mode(7'b0_0_0_0_0_0_0),
		  .output_reset(0),
		  .output_sync(7'b0_0_0_0_0_0_0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(",,,,,,"),
		  .pin_mode("OOOOOOO"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(7'b1_1_1_1_1_1_1),
		  .sio_ibuf(""),
		  .sio_info(14'b00_00_00_00_00_00_00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(7'b0_0_0_0_0_0_0),
		  .spanning(0),
		  .use_annotation(7'b0_0_0_0_0_0_0),
		  .vtrip(14'b10_10_10_10_10_10_10),
		  .width(7),
		  .ovt_hyst_trim(7'b0_0_0_0_0_0_0),
		  .ovt_needed(7'b0_0_0_0_0_0_0),
		  .ovt_slew_control(14'b00_00_00_00_00_00_00),
		  .input_buffer_sel(14'b00_00_00_00_00_00_00))
		LCDPort
		 (.oe(tmpOE__LCDPort_net),
		  .y({7'b0}),
		  .fb({tmpFB_6__LCDPort_net[6:0]}),
		  .io({tmpIO_6__LCDPort_net[6:0]}),
		  .siovref(tmpSIOVREF__LCDPort_net),
		  .interrupt({tmpINTERRUPT_0__LCDPort_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LCDPort_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{7'b1111111} : {7'b1111111};



endmodule

// VDAC8_v1_90(Data_Source=0, Initial_Value=25, Strobe_Mode=0, VDAC_Range=0, VDAC_Speed=0, Voltage=100, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=VDAC8_v1_90, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=VDAC8_1, CY_INSTANCE_SHORT_NAME=VDAC8_1, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=90, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=VDAC8_1, )
module VDAC8_v1_90_4 (
    strobe,
    data,
    vOut);
    input       strobe;
    input      [7:0] data;
    inout       vOut;
    electrical  vOut;

    parameter Data_Source = 0;
    parameter Initial_Value = 25;
    parameter Strobe_Mode = 0;

    electrical  Net_77;
          wire  Net_83;
          wire  Net_82;
          wire  Net_81;

    cy_psoc3_vidac8_v1_0 viDAC8 (
        .reset(Net_83),
        .idir(Net_81),
        .data(data[7:0]),
        .strobe(strobe),
        .vout(vOut),
        .iout(Net_77),
        .ioff(Net_82),
        .strobe_udb(strobe));
    defparam viDAC8.is_all_if_any = 0;
    defparam viDAC8.reg_data = 0;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_81));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_82));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_83));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_77));



endmodule

// Component: cy_vref_v1_60
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60\cy_vref_v1_60.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60\cy_vref_v1_60.v"
`endif

// Component: AMux_v1_80
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMux_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMux_v1_80\AMux_v1_80.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMux_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMux_v1_80\AMux_v1_80.v"
`endif

// ADC_DelSig_v3_20(ADC_Alignment=0, ADC_Alignment_Config2=0, ADC_Alignment_Config3=0, ADC_Alignment_Config4=0, ADC_Charge_Pump_Clock=true, ADC_Clock=1, ADC_CLOCK_FREQUENCY=524000, ADC_Input_Mode=1, ADC_Input_Range=0, ADC_Input_Range_Config2=0, ADC_Input_Range_Config3=0, ADC_Input_Range_Config4=0, ADC_Power=1, ADC_Reference=0, ADC_Reference_Config2=0, ADC_Reference_Config3=0, ADC_Reference_Config4=0, ADC_Resolution=12, ADC_Resolution_Config2=16, ADC_Resolution_Config3=16, ADC_Resolution_Config4=16, Clock_Frequency=64000, Comment_Config1=Default Config, Comment_Config2=Second Config, Comment_Config3=Third Config, Comment_Config4=Fourth Config, Config1_Name=CFG1, Config2_Name=CFG2, Config3_Name=CFG3, Config4_Name=CFG4, Configs=4, Conversion_Mode=1, Conversion_Mode_Config2=2, Conversion_Mode_Config3=2, Conversion_Mode_Config4=2, Enable_Vref_Vss=false, EnableModulatorInput=false, Input_Buffer_Gain=1, Input_Buffer_Gain_Config2=1, Input_Buffer_Gain_Config3=1, Input_Buffer_Gain_Config4=1, Input_Buffer_Mode=1, Input_Buffer_Mode_Config2=1, Input_Buffer_Mode_Config3=1, Input_Buffer_Mode_Config4=1, Ref_Voltage=1.024, Ref_Voltage_Config2=1.024, Ref_Voltage_Config3=1.024, Ref_Voltage_Config4=1.024, rm_int=false, Sample_Rate=4000, Sample_Rate_Config2=10000, Sample_Rate_Config3=10000, Sample_Rate_Config4=10000, Start_of_Conversion=0, Vdda_Value=5, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=ADC_DelSig_v3_20, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=ADC, CY_INSTANCE_SHORT_NAME=ADC, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=20, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=ADC, )
module ADC_DelSig_v3_20_5 (
    vplus,
    vminus,
    soc,
    eoc,
    aclk,
    nVref,
    mi);
    inout       vplus;
    electrical  vplus;
    inout       vminus;
    electrical  vminus;
    input       soc;
    output      eoc;
    input       aclk;
    inout       nVref;
    electrical  nVref;
    input       mi;


          wire  Net_268;
          wire  Net_270;
          wire  Net_252;
          wire  Net_275;
          wire  Net_250;
    electrical  Net_249;
    electrical  Net_257;
    electrical  Net_248;
    electrical  Net_23;
          wire  Net_247;
          wire  aclock;
          wire [3:0] mod_dat;
          wire  mod_reset;
    electrical  Net_352;
          wire  Net_246;
          wire [7:0] Net_245;
          wire  Net_482;
    electrical  Net_34;
    electrical  Net_35;
    electrical  Net_244;
          wire  Net_93;
    electrical  Net_20;
    electrical  Net_690;
    electrical  Net_686;
    electrical  Net_520;
          wire  Net_481;
    electrical  Net_677;
    electrical  Net_41;
    electrical  Net_573;
    electrical  Net_109;
          wire  Net_488;


	cy_vref_v1_0
		#(.autoenable(1),
		  .guid("15B3DB15-B7B3-4d62-A2DF-25EA392A7161"),
		  .name("Vssa (GND)"))
		vRef_2
		 (.vout(Net_244));


	// cy_analog_virtualmux_6 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_6_connect(Net_690, Net_35);
	defparam cy_analog_virtualmux_6_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_34));

	// cy_analog_virtualmux_4 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_4_connect(Net_677, Net_34);
	defparam cy_analog_virtualmux_4_connect.sig_width = 1;

    // -- AMux AMux start -- ***
    // -- Mux A --
    
    cy_psoc3_amux_v1_0 AMux(
        .muxin({
            Net_690,
            Net_244
            }),
        .vout(Net_20)
        );
    
    defparam AMux.muxin_width = 2;
    defparam AMux.init_mux_sel = 2'h0;
    defparam AMux.one_active = 0;
    defparam AMux.connect_mode = 1;
    
    // -- AMux AMux end --

    cy_psoc3_ds_mod_v4_0 DSM (
        .vplus(vplus),
        .vminus(Net_520),
        .modbit(Net_481),
        .reset_udb(Net_482),
        .aclock(Net_488),
        .mod_dat(mod_dat[3:0]),
        .dout_udb(Net_245[7:0]),
        .reset_dec(mod_reset),
        .dec_clock(aclock),
        .extclk_cp_udb(Net_93),
        .clk_udb(1'b0),
        .ext_pin_1(Net_573),
        .ext_pin_2(Net_41),
        .ext_vssa(Net_109),
        .qtz_ref(Net_677));
    defparam DSM.resolution = 12;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_5 (
        .noconnect(Net_352));

	// cy_analog_virtualmux_5 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_5_connect(Net_109, Net_352);
	defparam cy_analog_virtualmux_5_connect.sig_width = 1;


	cy_clock_v1_0
		#(.id("32d3f325-f96c-4620-8a75-7e66613695b2/b7604721-db56-4477-98c2-8fae77869066"),
		  .source_clock_id("61737EF6-3B74-48f9-8B91-F7473A442AE7"),
		  .divisor(1),
		  .period("0"),
		  .is_direct(0),
		  .is_digital(1))
		Ext_CP_Clk
		 (.clock_out(Net_93));


    cy_analog_noconnect_v1_0 cy_analog_noconnect_3 (
        .noconnect(Net_257));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_249));

	// cy_analog_virtualmux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_3_connect(Net_41, Net_257);
	defparam cy_analog_virtualmux_3_connect.sig_width = 1;

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_573, Net_249);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_520, Net_20);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;


	cy_isr_v1_0
		#(.int_type(2'b10))
		IRQ
		 (.int_signal(eoc));


	// Clock_VirtualMux (cy_virtualmux_v1_0)
	assign Net_488 = Net_250;


	cy_clock_v1_0
		#(.id("32d3f325-f96c-4620-8a75-7e66613695b2/edd15f43-b66b-457b-be3a-5342345270c8"),
		  .source_clock_id("61737EF6-3B74-48f9-8B91-F7473A442AE7"),
		  .divisor(0),
		  .period("1908396946.56489"),
		  .is_direct(0),
		  .is_digital(0))
		theACLK
		 (.clock_out(Net_250));


    ZeroTerminal ZeroTerminal_2 (
        .z(Net_482));

	// Clock_VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_481 = Net_252;

    cy_psoc3_decimator_v1_0 DEC (
        .aclock(aclock),
        .mod_dat(mod_dat[3:0]),
        .ext_start(soc),
        .mod_reset(mod_reset),
        .interrupt(eoc));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_252));


    assign Net_268 = Net_270 | Net_93;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_270));



endmodule

// PGA_v2_0(Gain=0, Power=3, VddaValue=5, Vref_Input=0, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=PGA_v2_0, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=PGA, CY_INSTANCE_SHORT_NAME=PGA, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=PGA, )
module PGA_v2_0_6 (
    Vin,
    Vref,
    Vout);
    inout       Vin;
    electrical  Vin;
    inout       Vref;
    electrical  Vref;
    inout       Vout;
    electrical  Vout;


    electrical  Net_75;
          wire  Net_41;
          wire  Net_40;
    electrical  Net_17;
          wire  Net_39;
          wire  Net_38;
          wire  Net_37;

    cy_psoc3_scblock_v1_0 SC (
        .vin(Vin),
        .vref(Net_17),
        .vout(Vout),
        .modout_sync(Net_41),
        .aclk(Net_37),
        .clk_udb(Net_38),
        .dyn_cntl(Net_39),
        .bst_clk(Net_40));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_37));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_38));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_39));

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_40));

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_17, Net_75);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_75));



endmodule

// Component: bScanComp_v1_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bScanComp_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bScanComp_v1_10\bScanComp_v1_10.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bScanComp_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bScanComp_v1_10\bScanComp_v1_10.v"
`endif

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// Comp_v2_0(Hysteresis=0, Pd_Override=0, Polarity=0, PSOC5A=false, Speed=2, Sync=1, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=Comp_v2_0, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SensorScan:Comp, CY_INSTANCE_SHORT_NAME=Comp, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=SensorScan_Comp, )
module Comp_v2_0_7 (
    Vplus,
    CmpOut,
    Vminus,
    clock);
    inout       Vplus;
    electrical  Vplus;
    output      CmpOut;
    inout       Vminus;
    electrical  Vminus;
    input       clock;


          wire  Net_9;
          wire  Net_1;

    cy_psoc3_ctcomp_v1_0 ctComp (
        .vplus(Vplus),
        .vminus(Vminus),
        .cmpout(Net_1),
        .clk_udb(clock),
        .clock(clock));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign CmpOut = Net_1;


    assign Net_9 = ~Net_1;



endmodule

// Component: ScanCompAMux_v1_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\ScanCompAMux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\ScanCompAMux_v1_10\ScanCompAMux_v1_10.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\ScanCompAMux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\ScanCompAMux_v1_10\ScanCompAMux_v1_10.v"
`endif

// ScanComp_v1_10(ClockSource=0, FixedVoltage=125, FixedVoltageMv=2000, InternalModeExist=0, IntModeList=<?xml version="1.0" encoding="utf-16"?>\r\n<ArrayOfString xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">\r\n  <string>INTR_BOTH</string>\r\n  <string>INTR_BOTH</string>\r\n  <string>INTR_BOTH</string>\r\n  <string>INTR_BOTH</string>\r\n  <string>INTR_BOTH</string>\r\n</ArrayOfString>, OutputsEnable=true, SeqChannelsConfigTable=<?xml version="1.0" encoding="utf-16"?> <CyChannelsTable xmlns:Version="1_10">   <ChannelsList>     <CyChannelsTableRow>       <InterruptMode>INTR_BOTH</InterruptMode>       <DacVoltage>2000</DacVoltage>     </CyChannelsTableRow>     <CyChannelsTableRow>       <InterruptMode>INTR_BOTH</InterruptMode>       <DacVoltage>2000</DacVoltage>     </CyChannelsTableRow>     <CyChannelsTableRow>       <InterruptMode>INTR_BOTH</InterruptMode>       <DacVoltage>2000</DacVoltage>     </CyChannelsTableRow>     <CyChannelsTableRow>       <InterruptMode>INTR_BOTH</InterruptMode>       <DacVoltage>2000</DacVoltage>     </CyChannelsTableRow>     <CyChannelsTableRow>       <InterruptMode>INTR_BOTH</InterruptMode>       <DacVoltage>2000</DacVoltage>     </CyChannelsTableRow>   </ChannelsList> </CyChannelsTable>, SequencedChannels=5, SpeedPower=2, TimingFrequency=6000, TimingRate=1000, TimingType=0, VDACRange=4, VoltageMode=0, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=ScanComp_v1_10, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SensorScan, CY_INSTANCE_SHORT_NAME=SensorScan, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=10, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=SensorScan, )
module ScanComp_v1_10_8 (
    clock,
    interrupt,
    eos,
    CmpOut0,
    CmpOut1,
    CmpOut2,
    CmpOut3,
    CmpOut4,
    CmpOut5,
    CmpOut6,
    CmpOut7,
    CmpOut8,
    CmpOut9,
    CmpOut10,
    CmpOut11,
    CmpOut12,
    CmpOut13,
    CmpOut14,
    CmpOut15,
    CmpOut16,
    CmpOut17,
    CmpOut18,
    CmpOut19,
    CmpOut20,
    CmpOut21,
    CmpOut22,
    CmpOut23,
    CmpOut24,
    CmpOut25,
    CmpOut26,
    CmpOut27,
    CmpOut28,
    CmpOut29,
    CmpOut30,
    CmpOut31,
    CmpOut32,
    CmpOut33,
    CmpOut34,
    CmpOut35,
    CmpOut36,
    CmpOut37,
    CmpOut38,
    CmpOut39,
    CmpOut40,
    CmpOut41,
    CmpOut42,
    CmpOut43,
    CmpOut44,
    CmpOut45,
    CmpOut46,
    CmpOut47,
    CmpOut48,
    CmpOut49,
    CmpOut50,
    CmpOut51,
    CmpOut52,
    CmpOut53,
    CmpOut54,
    CmpOut55,
    CmpOut56,
    CmpOut57,
    CmpOut58,
    CmpOut59,
    CmpOut60,
    CmpOut61,
    CmpOut62,
    CmpOut63,
    AIN_10,
    AIN_11,
    AIN1,
    AIN_20,
    AIN_21,
    AIN_30,
    AIN_31,
    AIN3,
    AIN_40,
    AIN_41,
    AIN_50,
    AIN_51,
    AIN5,
    AIN_60,
    AIN_61,
    AIN_70,
    AIN_71,
    AIN7,
    AIN_80,
    AIN_81,
    AIN_90,
    AIN_91,
    AIN9,
    AIN_100,
    AIN_101,
    AIN_110,
    AIN_111,
    AIN11,
    AIN_120,
    AIN_121,
    AIN_130,
    AIN_131,
    AIN13,
    AIN_140,
    AIN_141,
    AIN_150,
    AIN_151,
    AIN15,
    AIN_160,
    AIN_161,
    AIN_170,
    AIN_171,
    AIN17,
    AIN_180,
    AIN_181,
    AIN_190,
    AIN_191,
    AIN19,
    AIN_200,
    AIN_201,
    AIN_210,
    AIN_211,
    AIN21,
    AIN_220,
    AIN_221,
    AIN_230,
    AIN_231,
    AIN23,
    AIN_240,
    AIN_241,
    AIN_250,
    AIN_251,
    AIN25,
    AIN_260,
    AIN_261,
    AIN_270,
    AIN_271,
    AIN27,
    AIN_280,
    AIN_281,
    AIN_290,
    AIN_291,
    AIN29,
    AIN_300,
    AIN_301,
    AIN_310,
    AIN_311,
    AIN31,
    AIN_320,
    AIN_321,
    AIN_450,
    AIN_451,
    AIN_460,
    AIN_461,
    AIN_470,
    AIN_471,
    AIN_480,
    AIN_481,
    AIN_490,
    AIN_491,
    AIN_500,
    AIN_501,
    AIN_510,
    AIN_511,
    AIN_520,
    AIN_521,
    AIN_330,
    AIN_331,
    AIN33,
    AIN_340,
    AIN_341,
    AIN_350,
    AIN_351,
    AIN35,
    AIN_360,
    AIN_361,
    AIN_370,
    AIN_371,
    AIN37,
    AIN_380,
    AIN_381,
    AIN_390,
    AIN_391,
    AIN39,
    AIN_400,
    AIN_401,
    AIN_410,
    AIN_411,
    AIN41,
    AIN_420,
    AIN_421,
    AIN_430,
    AIN_431,
    AIN_440,
    AIN_441,
    AIN_530,
    AIN_531,
    AIN_540,
    AIN_541,
    AIN_550,
    AIN_551,
    AIN_560,
    AIN_561,
    AIN_570,
    AIN_571,
    AIN_580,
    AIN_581,
    AIN_590,
    AIN_591,
    AIN_600,
    AIN_601,
    AIN_610,
    AIN_611,
    AIN_620,
    AIN_621,
    AIN_630,
    AIN_631,
    AIN_640,
    AIN_641,
    Vminus);
    input       clock;
    output      interrupt;
    output      eos;
    output      CmpOut0;
    output      CmpOut1;
    output      CmpOut2;
    output      CmpOut3;
    output      CmpOut4;
    output      CmpOut5;
    output      CmpOut6;
    output      CmpOut7;
    output      CmpOut8;
    output      CmpOut9;
    output      CmpOut10;
    output      CmpOut11;
    output      CmpOut12;
    output      CmpOut13;
    output      CmpOut14;
    output      CmpOut15;
    output      CmpOut16;
    output      CmpOut17;
    output      CmpOut18;
    output      CmpOut19;
    output      CmpOut20;
    output      CmpOut21;
    output      CmpOut22;
    output      CmpOut23;
    output      CmpOut24;
    output      CmpOut25;
    output      CmpOut26;
    output      CmpOut27;
    output      CmpOut28;
    output      CmpOut29;
    output      CmpOut30;
    output      CmpOut31;
    output      CmpOut32;
    output      CmpOut33;
    output      CmpOut34;
    output      CmpOut35;
    output      CmpOut36;
    output      CmpOut37;
    output      CmpOut38;
    output      CmpOut39;
    output      CmpOut40;
    output      CmpOut41;
    output      CmpOut42;
    output      CmpOut43;
    output      CmpOut44;
    output      CmpOut45;
    output      CmpOut46;
    output      CmpOut47;
    output      CmpOut48;
    output      CmpOut49;
    output      CmpOut50;
    output      CmpOut51;
    output      CmpOut52;
    output      CmpOut53;
    output      CmpOut54;
    output      CmpOut55;
    output      CmpOut56;
    output      CmpOut57;
    output      CmpOut58;
    output      CmpOut59;
    output      CmpOut60;
    output      CmpOut61;
    output      CmpOut62;
    output      CmpOut63;
    inout       AIN_10;
    electrical  AIN_10;
    inout       AIN_11;
    electrical  AIN_11;
    inout       AIN1;
    electrical  AIN1;
    inout       AIN_20;
    electrical  AIN_20;
    inout       AIN_21;
    electrical  AIN_21;
    inout       AIN_30;
    electrical  AIN_30;
    inout       AIN_31;
    electrical  AIN_31;
    inout       AIN3;
    electrical  AIN3;
    inout       AIN_40;
    electrical  AIN_40;
    inout       AIN_41;
    electrical  AIN_41;
    inout       AIN_50;
    electrical  AIN_50;
    inout       AIN_51;
    electrical  AIN_51;
    inout       AIN5;
    electrical  AIN5;
    inout       AIN_60;
    electrical  AIN_60;
    inout       AIN_61;
    electrical  AIN_61;
    inout       AIN_70;
    electrical  AIN_70;
    inout       AIN_71;
    electrical  AIN_71;
    inout       AIN7;
    electrical  AIN7;
    inout       AIN_80;
    electrical  AIN_80;
    inout       AIN_81;
    electrical  AIN_81;
    inout       AIN_90;
    electrical  AIN_90;
    inout       AIN_91;
    electrical  AIN_91;
    inout       AIN9;
    electrical  AIN9;
    inout       AIN_100;
    electrical  AIN_100;
    inout       AIN_101;
    electrical  AIN_101;
    inout       AIN_110;
    electrical  AIN_110;
    inout       AIN_111;
    electrical  AIN_111;
    inout       AIN11;
    electrical  AIN11;
    inout       AIN_120;
    electrical  AIN_120;
    inout       AIN_121;
    electrical  AIN_121;
    inout       AIN_130;
    electrical  AIN_130;
    inout       AIN_131;
    electrical  AIN_131;
    inout       AIN13;
    electrical  AIN13;
    inout       AIN_140;
    electrical  AIN_140;
    inout       AIN_141;
    electrical  AIN_141;
    inout       AIN_150;
    electrical  AIN_150;
    inout       AIN_151;
    electrical  AIN_151;
    inout       AIN15;
    electrical  AIN15;
    inout       AIN_160;
    electrical  AIN_160;
    inout       AIN_161;
    electrical  AIN_161;
    inout       AIN_170;
    electrical  AIN_170;
    inout       AIN_171;
    electrical  AIN_171;
    inout       AIN17;
    electrical  AIN17;
    inout       AIN_180;
    electrical  AIN_180;
    inout       AIN_181;
    electrical  AIN_181;
    inout       AIN_190;
    electrical  AIN_190;
    inout       AIN_191;
    electrical  AIN_191;
    inout       AIN19;
    electrical  AIN19;
    inout       AIN_200;
    electrical  AIN_200;
    inout       AIN_201;
    electrical  AIN_201;
    inout       AIN_210;
    electrical  AIN_210;
    inout       AIN_211;
    electrical  AIN_211;
    inout       AIN21;
    electrical  AIN21;
    inout       AIN_220;
    electrical  AIN_220;
    inout       AIN_221;
    electrical  AIN_221;
    inout       AIN_230;
    electrical  AIN_230;
    inout       AIN_231;
    electrical  AIN_231;
    inout       AIN23;
    electrical  AIN23;
    inout       AIN_240;
    electrical  AIN_240;
    inout       AIN_241;
    electrical  AIN_241;
    inout       AIN_250;
    electrical  AIN_250;
    inout       AIN_251;
    electrical  AIN_251;
    inout       AIN25;
    electrical  AIN25;
    inout       AIN_260;
    electrical  AIN_260;
    inout       AIN_261;
    electrical  AIN_261;
    inout       AIN_270;
    electrical  AIN_270;
    inout       AIN_271;
    electrical  AIN_271;
    inout       AIN27;
    electrical  AIN27;
    inout       AIN_280;
    electrical  AIN_280;
    inout       AIN_281;
    electrical  AIN_281;
    inout       AIN_290;
    electrical  AIN_290;
    inout       AIN_291;
    electrical  AIN_291;
    inout       AIN29;
    electrical  AIN29;
    inout       AIN_300;
    electrical  AIN_300;
    inout       AIN_301;
    electrical  AIN_301;
    inout       AIN_310;
    electrical  AIN_310;
    inout       AIN_311;
    electrical  AIN_311;
    inout       AIN31;
    electrical  AIN31;
    inout       AIN_320;
    electrical  AIN_320;
    inout       AIN_321;
    electrical  AIN_321;
    inout       AIN_450;
    electrical  AIN_450;
    inout       AIN_451;
    electrical  AIN_451;
    inout       AIN_460;
    electrical  AIN_460;
    inout       AIN_461;
    electrical  AIN_461;
    inout       AIN_470;
    electrical  AIN_470;
    inout       AIN_471;
    electrical  AIN_471;
    inout       AIN_480;
    electrical  AIN_480;
    inout       AIN_481;
    electrical  AIN_481;
    inout       AIN_490;
    electrical  AIN_490;
    inout       AIN_491;
    electrical  AIN_491;
    inout       AIN_500;
    electrical  AIN_500;
    inout       AIN_501;
    electrical  AIN_501;
    inout       AIN_510;
    electrical  AIN_510;
    inout       AIN_511;
    electrical  AIN_511;
    inout       AIN_520;
    electrical  AIN_520;
    inout       AIN_521;
    electrical  AIN_521;
    inout       AIN_330;
    electrical  AIN_330;
    inout       AIN_331;
    electrical  AIN_331;
    inout       AIN33;
    electrical  AIN33;
    inout       AIN_340;
    electrical  AIN_340;
    inout       AIN_341;
    electrical  AIN_341;
    inout       AIN_350;
    electrical  AIN_350;
    inout       AIN_351;
    electrical  AIN_351;
    inout       AIN35;
    electrical  AIN35;
    inout       AIN_360;
    electrical  AIN_360;
    inout       AIN_361;
    electrical  AIN_361;
    inout       AIN_370;
    electrical  AIN_370;
    inout       AIN_371;
    electrical  AIN_371;
    inout       AIN37;
    electrical  AIN37;
    inout       AIN_380;
    electrical  AIN_380;
    inout       AIN_381;
    electrical  AIN_381;
    inout       AIN_390;
    electrical  AIN_390;
    inout       AIN_391;
    electrical  AIN_391;
    inout       AIN39;
    electrical  AIN39;
    inout       AIN_400;
    electrical  AIN_400;
    inout       AIN_401;
    electrical  AIN_401;
    inout       AIN_410;
    electrical  AIN_410;
    inout       AIN_411;
    electrical  AIN_411;
    inout       AIN41;
    electrical  AIN41;
    inout       AIN_420;
    electrical  AIN_420;
    inout       AIN_421;
    electrical  AIN_421;
    inout       AIN_430;
    electrical  AIN_430;
    inout       AIN_431;
    electrical  AIN_431;
    inout       AIN_440;
    electrical  AIN_440;
    inout       AIN_441;
    electrical  AIN_441;
    inout       AIN_530;
    electrical  AIN_530;
    inout       AIN_531;
    electrical  AIN_531;
    inout       AIN_540;
    electrical  AIN_540;
    inout       AIN_541;
    electrical  AIN_541;
    inout       AIN_550;
    electrical  AIN_550;
    inout       AIN_551;
    electrical  AIN_551;
    inout       AIN_560;
    electrical  AIN_560;
    inout       AIN_561;
    electrical  AIN_561;
    inout       AIN_570;
    electrical  AIN_570;
    inout       AIN_571;
    electrical  AIN_571;
    inout       AIN_580;
    electrical  AIN_580;
    inout       AIN_581;
    electrical  AIN_581;
    inout       AIN_590;
    electrical  AIN_590;
    inout       AIN_591;
    electrical  AIN_591;
    inout       AIN_600;
    electrical  AIN_600;
    inout       AIN_601;
    electrical  AIN_601;
    inout       AIN_610;
    electrical  AIN_610;
    inout       AIN_611;
    electrical  AIN_611;
    inout       AIN_620;
    electrical  AIN_620;
    inout       AIN_621;
    electrical  AIN_621;
    inout       AIN_630;
    electrical  AIN_630;
    inout       AIN_631;
    electrical  AIN_631;
    inout       AIN_640;
    electrical  AIN_640;
    inout       AIN_641;
    electrical  AIN_641;
    inout       Vminus;
    electrical  Vminus;

    parameter OutputsEnable = 1;
    parameter SequencedChannels = 5;

          wire  Net_778;
          wire  clk;
          wire [7:0] Net_780;
          wire [5:0] ch_addr;
          wire  Net_779;
          wire  Net_782;
          wire  Net_781;
          wire  Net_777;
          wire  Net_776;
          wire  Net_775;
    electrical  Net_8105;
          wire  Net_8227;
    electrical  Net_6163;
    electrical  Net_5517;
    electrical  V_minus;
    electrical  V_single;
    electrical  V_plus;
          wire  Net_5511;
          wire [63:0] ch;
          wire  Net_3474;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign clk = Net_3474;


	cy_clock_v1_0
		#(.id("44cb4c3c-f111-43eb-aa5b-931e3bd5539d/3830ea91-5340-4147-9ad7-597e825b22a7"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("166666666666.667"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_int
		 (.clock_out(Net_3474));


	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_5517, V_single);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

    bScanComp_v1_10 bScanComp (
        .clk(clk),
        .ch_addr(ch_addr[5:0]),
        .ch(ch[63:0]),
        .comp_o(Net_5511),
        .interrupt(interrupt),
        .drq(Net_8227),
        .eos(eos));
    defparam bScanComp.AvailableChannels = 5;
    defparam bScanComp.ChannelsBitValue = 2;
    defparam bScanComp.EdgeType0 = 2;
    defparam bScanComp.EdgeType1 = 2;
    defparam bScanComp.EdgeType10 = 3;
    defparam bScanComp.EdgeType11 = 3;
    defparam bScanComp.EdgeType12 = 3;
    defparam bScanComp.EdgeType13 = 3;
    defparam bScanComp.EdgeType14 = 3;
    defparam bScanComp.EdgeType15 = 3;
    defparam bScanComp.EdgeType16 = 3;
    defparam bScanComp.EdgeType17 = 3;
    defparam bScanComp.EdgeType18 = 3;
    defparam bScanComp.EdgeType19 = 3;
    defparam bScanComp.EdgeType2 = 2;
    defparam bScanComp.EdgeType20 = 3;
    defparam bScanComp.EdgeType21 = 3;
    defparam bScanComp.EdgeType22 = 3;
    defparam bScanComp.EdgeType23 = 3;
    defparam bScanComp.EdgeType24 = 3;
    defparam bScanComp.EdgeType25 = 3;
    defparam bScanComp.EdgeType26 = 3;
    defparam bScanComp.EdgeType27 = 3;
    defparam bScanComp.EdgeType28 = 3;
    defparam bScanComp.EdgeType29 = 3;
    defparam bScanComp.EdgeType3 = 2;
    defparam bScanComp.EdgeType30 = 3;
    defparam bScanComp.EdgeType31 = 3;
    defparam bScanComp.EdgeType32 = 3;
    defparam bScanComp.EdgeType33 = 3;
    defparam bScanComp.EdgeType34 = 3;
    defparam bScanComp.EdgeType35 = 3;
    defparam bScanComp.EdgeType36 = 3;
    defparam bScanComp.EdgeType37 = 3;
    defparam bScanComp.EdgeType38 = 3;
    defparam bScanComp.EdgeType39 = 3;
    defparam bScanComp.EdgeType4 = 2;
    defparam bScanComp.EdgeType40 = 3;
    defparam bScanComp.EdgeType41 = 3;
    defparam bScanComp.EdgeType42 = 3;
    defparam bScanComp.EdgeType43 = 3;
    defparam bScanComp.EdgeType44 = 3;
    defparam bScanComp.EdgeType45 = 3;
    defparam bScanComp.EdgeType46 = 3;
    defparam bScanComp.EdgeType47 = 3;
    defparam bScanComp.EdgeType48 = 3;
    defparam bScanComp.EdgeType49 = 3;
    defparam bScanComp.EdgeType5 = 3;
    defparam bScanComp.EdgeType50 = 3;
    defparam bScanComp.EdgeType51 = 3;
    defparam bScanComp.EdgeType52 = 3;
    defparam bScanComp.EdgeType53 = 3;
    defparam bScanComp.EdgeType54 = 3;
    defparam bScanComp.EdgeType55 = 3;
    defparam bScanComp.EdgeType56 = 3;
    defparam bScanComp.EdgeType57 = 3;
    defparam bScanComp.EdgeType58 = 3;
    defparam bScanComp.EdgeType59 = 3;
    defparam bScanComp.EdgeType6 = 3;
    defparam bScanComp.EdgeType60 = 3;
    defparam bScanComp.EdgeType61 = 3;
    defparam bScanComp.EdgeType62 = 3;
    defparam bScanComp.EdgeType63 = 3;
    defparam bScanComp.EdgeType7 = 3;
    defparam bScanComp.EdgeType8 = 3;
    defparam bScanComp.EdgeType9 = 3;
    defparam bScanComp.InterruptBitValue = 0;
    defparam bScanComp.OutputsEnable = 1;


    assign Net_777 = Net_776 | Net_3474;

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_6163, Vminus);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

    ZeroTerminal ZeroTerminal_8 (
        .z(Net_776));

    Comp_v2_0_7 Comp (
        .Vplus(Net_5517),
        .CmpOut(Net_5511),
        .Vminus(Net_6163),
        .clock(1'b0));

    // -- AMuxHw ScanCompAMuxSingle start -- ***
    
    // -- AMuxHw Decoder Start--
    
    reg [63:0] ScanCompAMuxSingle_Decoder_one_hot;
    reg [5:0] ScanCompAMuxSingle_Decoder_old_id;
    wire  ScanCompAMuxSingle_Decoder_is_active;
    wire  ScanCompAMuxSingle_Decoder_enable;
    
    assign ScanCompAMuxSingle_Decoder_enable = 1'b1;
    
    genvar ScanCompAMuxSingle_Decoder_i;
    
    assign ScanCompAMuxSingle_Decoder_is_active = (ch_addr[5:0] == ScanCompAMuxSingle_Decoder_old_id) && ScanCompAMuxSingle_Decoder_enable;
    
    always @(posedge clk)
    begin
        ScanCompAMuxSingle_Decoder_old_id = ch_addr[5:0];
    end
    
    generate
        for (ScanCompAMuxSingle_Decoder_i = 0; ScanCompAMuxSingle_Decoder_i < 64; ScanCompAMuxSingle_Decoder_i = ScanCompAMuxSingle_Decoder_i + 1 )
        begin : ScanCompAMuxSingle_OutBit
            always @(posedge clk)
            begin
                ScanCompAMuxSingle_Decoder_one_hot[ScanCompAMuxSingle_Decoder_i] <= (ScanCompAMuxSingle_Decoder_old_id == ScanCompAMuxSingle_Decoder_i) && ScanCompAMuxSingle_Decoder_is_active;
            end
        end
    endgenerate
    
    // -- AMuxHw Decoder End--
    
    // -- AMuxHw Primitive A --
    
    cy_psoc3_amux_v1_0 #(
        .muxin_width(64),
        .hw_control(1),
        .one_active(1),
        .init_mux_sel(64'h0),
        .api_type(2'b10))
        ScanCompAMuxSingle(
        .muxin({
            AIN_430,
            AIN_421,
            AIN41,
            AIN_410,
            AIN_401,
            AIN39,
            AIN_390,
            AIN_381,
            AIN37,
            AIN_370,
            AIN_361,
            AIN35,
            AIN_350,
            AIN_341,
            AIN33,
            AIN_330,
            AIN_321,
            AIN31,
            AIN_310,
            AIN_301,
            AIN29,
            AIN_290,
            AIN_281,
            AIN27,
            AIN_270,
            AIN_261,
            AIN25,
            AIN_250,
            AIN_241,
            AIN23,
            AIN_230,
            AIN_221,
            AIN21,
            AIN_210,
            AIN_201,
            AIN19,
            AIN_190,
            AIN_181,
            AIN17,
            AIN_170,
            AIN_161,
            AIN15,
            AIN_150,
            AIN_141,
            AIN13,
            AIN_130,
            AIN_121,
            AIN11,
            AIN_110,
            AIN_101,
            AIN9,
            AIN_90,
            AIN_81,
            AIN7,
            AIN_70,
            AIN_61,
            AIN5,
            AIN_50,
            AIN_41,
            AIN3,
            AIN_30,
            AIN_21,
            AIN1,
            AIN_10
            }),
        .hw_ctrl_en(ScanCompAMuxSingle_Decoder_one_hot[63:0]),
        .vout(V_single)
        );
    
    // -- AMuxHw ScanCompAMuxSingle end -- ***


    assign CmpOut0 = ch[0];

    assign CmpOut1 = ch[1];

    assign CmpOut2 = ch[2];

    assign CmpOut3 = ch[3];

    assign CmpOut4 = ch[4];

    assign CmpOut5 = ch[5];

    assign CmpOut6 = ch[6];

    assign CmpOut7 = ch[7];

    assign CmpOut8 = ch[8];

    assign CmpOut9 = ch[9];

    assign CmpOut10 = ch[10];

    assign CmpOut11 = ch[11];

    assign CmpOut12 = ch[12];

    assign CmpOut13 = ch[13];

    assign CmpOut14 = ch[14];

    assign CmpOut15 = ch[15];

    assign CmpOut16 = ch[16];

    assign CmpOut17 = ch[17];

    assign CmpOut18 = ch[18];

    assign CmpOut19 = ch[19];

    assign CmpOut20 = ch[20];

    assign CmpOut21 = ch[21];

    assign CmpOut22 = ch[22];

    assign CmpOut23 = ch[23];

    assign CmpOut24 = ch[24];

    assign CmpOut25 = ch[25];

    assign CmpOut26 = ch[26];

    assign CmpOut27 = ch[27];

    assign CmpOut28 = ch[28];

    assign CmpOut29 = ch[29];

    assign CmpOut30 = ch[30];

    assign CmpOut31 = ch[31];

    assign CmpOut32 = ch[32];

    assign CmpOut33 = ch[33];

    assign CmpOut34 = ch[34];

    assign CmpOut35 = ch[35];

    assign CmpOut36 = ch[36];

    assign CmpOut37 = ch[37];

    assign CmpOut38 = ch[38];

    assign CmpOut39 = ch[39];

    assign CmpOut40 = ch[40];

    assign CmpOut41 = ch[41];

    assign CmpOut42 = ch[42];

    assign CmpOut43 = ch[43];

    assign CmpOut44 = ch[44];

    assign CmpOut45 = ch[45];

    assign CmpOut46 = ch[46];

    assign CmpOut47 = ch[47];

    assign CmpOut48 = ch[48];

    assign CmpOut49 = ch[49];

    assign CmpOut50 = ch[50];

    assign CmpOut51 = ch[51];

    assign CmpOut52 = ch[52];

    assign CmpOut53 = ch[53];

    assign CmpOut54 = ch[54];

    assign CmpOut55 = ch[55];

    assign CmpOut56 = ch[56];

    assign CmpOut57 = ch[57];

    assign CmpOut58 = ch[58];

    assign CmpOut59 = ch[58];

    assign CmpOut60 = ch[60];

    assign CmpOut61 = ch[61];

    assign CmpOut62 = ch[62];

    assign CmpOut63 = ch[63];


endmodule

// top
module top ;

    electrical  Net_1403;
    electrical  Net_1402;
    electrical  Net_1401;
    electrical  Net_1400;
    electrical  Net_1399;
    electrical  Net_1398;
    electrical  Net_1397;
    electrical  Net_1396;
    electrical  Net_1395;
    electrical  Net_1394;
    electrical  Net_1393;
    electrical  Net_1392;
    electrical  Net_1391;
    electrical  Net_1390;
    electrical  Net_1389;
    electrical  Net_1388;
    electrical  Net_1387;
    electrical  Net_1386;
    electrical  Net_1385;
    electrical  Net_1384;
    electrical  Net_1383;
    electrical  Net_1382;
    electrical  Net_1381;
    electrical  Net_1380;
    electrical  Net_1379;
    electrical  Net_1378;
    electrical  Net_1377;
    electrical  Net_1376;
    electrical  Net_1375;
    electrical  Net_1374;
    electrical  Net_1373;
    electrical  Net_1372;
    electrical  Net_1371;
    electrical  Net_1370;
    electrical  Net_1369;
    electrical  Net_1368;
    electrical  Net_1367;
    electrical  Net_1366;
    electrical  Net_1365;
    electrical  Net_1364;
    electrical  Net_1363;
    electrical  Net_1362;
    electrical  Net_1361;
    electrical  Net_1360;
    electrical  Net_1359;
    electrical  Net_1358;
    electrical  Net_1357;
    electrical  Net_1356;
    electrical  Net_1355;
    electrical  Net_1354;
    electrical  Net_1353;
    electrical  Net_1352;
    electrical  Net_1351;
    electrical  Net_1350;
    electrical  Net_1349;
    electrical  Net_1348;
    electrical  Net_1347;
    electrical  Net_1346;
    electrical  Net_1345;
    electrical  Net_1344;
    electrical  Net_1343;
    electrical  Net_1342;
    electrical  Net_1341;
    electrical  Net_1340;
    electrical  Net_1339;
    electrical  Net_1338;
    electrical  Net_1337;
    electrical  Net_1336;
    electrical  Net_1335;
    electrical  Net_1334;
    electrical  Net_1333;
    electrical  Net_1332;
    electrical  Net_1331;
    electrical  Net_1330;
    electrical  Net_1329;
    electrical  Net_1328;
    electrical  Net_1327;
    electrical  Net_1326;
    electrical  Net_1325;
    electrical  Net_1324;
    electrical  Net_1323;
    electrical  Net_1322;
    electrical  Net_1321;
    electrical  Net_1320;
    electrical  Net_1319;
    electrical  Net_1318;
    electrical  Net_1317;
    electrical  Net_1316;
    electrical  Net_1315;
    electrical  Net_1314;
    electrical  Net_1313;
    electrical  Net_1312;
    electrical  Net_1311;
    electrical  Net_1310;
    electrical  Net_1309;
    electrical  Net_1308;
    electrical  Net_1307;
    electrical  Net_1306;
    electrical  Net_1305;
    electrical  Net_1304;
    electrical  Net_1303;
    electrical  Net_1302;
    electrical  Net_1301;
    electrical  Net_1300;
    electrical  Net_1299;
    electrical  Net_1298;
    electrical  Net_1297;
    electrical  Net_1296;
    electrical  Net_1295;
    electrical  Net_1294;
    electrical  Net_1293;
    electrical  Net_1292;
    electrical  Net_1291;
    electrical  Net_1290;
    electrical  Net_1289;
    electrical  Net_1288;
    electrical  Net_1287;
    electrical  Net_1286;
    electrical  Net_1285;
    electrical  Net_1284;
    electrical  Net_1283;
    electrical  Net_1282;
    electrical  Net_1281;
    electrical  Net_1280;
    electrical  Net_1279;
    electrical  Net_1278;
    electrical  Net_1277;
    electrical  Net_1276;
    electrical  Net_1275;
    electrical  Net_1274;
    electrical  Net_1273;
    electrical  Net_1272;
    electrical  Net_1271;
    electrical  Net_1270;
    electrical  Net_1269;
    electrical  Net_1268;
    electrical  Net_1267;
    electrical  Net_1266;
    electrical  Net_1265;
    electrical  Net_1264;
    electrical  Net_1263;
    electrical  Net_1261;
    electrical  Net_1258;
    electrical  Net_1256;
    electrical  Net_1189;
          wire  Net_1255;
          wire  Net_1254;
          wire  Net_1253;
          wire  Net_1252;
          wire  Net_1251;
          wire  Net_1250;
          wire  Net_1249;
          wire  Net_1248;
          wire  Net_1247;
          wire  Net_1246;
          wire  Net_1245;
          wire  Net_1244;
          wire  Net_1243;
          wire  Net_1242;
          wire  Net_1241;
          wire  Net_1240;
          wire  Net_1239;
          wire  Net_1238;
          wire  Net_1237;
          wire  Net_1236;
          wire  Net_1235;
          wire  Net_1234;
          wire  Net_1233;
          wire  Net_1232;
          wire  Net_1231;
          wire  Net_1230;
          wire  Net_1229;
          wire  Net_1228;
          wire  Net_1227;
          wire  Net_1226;
          wire  Net_1225;
          wire  Net_1224;
          wire  Net_1223;
          wire  Net_1222;
          wire  Net_1221;
          wire  Net_1220;
          wire  Net_1219;
          wire  Net_1218;
          wire  Net_1217;
          wire  Net_1216;
          wire  Net_1215;
          wire  Net_1214;
          wire  Net_1213;
          wire  Net_1212;
          wire  Net_1211;
          wire  Net_1210;
          wire  Net_1209;
          wire  Net_1208;
          wire  Net_1207;
          wire  Net_1206;
          wire  Net_1205;
          wire  Net_1204;
          wire  Net_1203;
          wire  Net_1202;
          wire  Net_1201;
          wire  Net_1200;
          wire  Net_1199;
          wire  Net_1198;
          wire  Net_1197;
          wire  Net_1190;
          wire  Net_1192;
          wire  Net_1191;
    electrical  Net_1257;
    electrical  Net_1259;
    electrical  Net_1260;
    electrical  Net_1262;
          wire  Net_1194;
          wire  Net_1196;
          wire  Net_1195;
          wire  Net_1193;
    electrical  Net_675;
          wire  Net_691;
    electrical  Net_690;
          wire  Net_689;
          wire  Net_688;
          wire  Net_687;
    electrical  Net_1159;
    electrical  Net_685;
          wire [7:0] Net_1188;
          wire  Net_1187;
          wire  Net_1186;
          wire  Net_1185;
          wire  Net_1148;
          wire  Net_1147;
          wire  Net_1184;
          wire  Net_1183;
    electrical  Net_663;
          wire  Net_546;
          wire  Net_540;
          wire  Net_539;
    electrical  Net_697;
          wire  Net_1178;
    electrical  Net_661;

    assign Net_539 = 1'h0;


	cy_clock_v1_0
		#(.id("d9c64ec5-0721-4c69-a9f0-a4ae422dbc86"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("4000000000"),
		  .is_direct(0),
		  .is_digital(1))
		SineWaveClock
		 (.clock_out(Net_540));


	wire [0:0] tmpOE__SineWave_net;
	wire [0:0] tmpFB_0__SineWave_net;
	wire [0:0] tmpIO_0__SineWave_net;
	wire [0:0] tmpINTERRUPT_0__SineWave_net;
	electrical [0:0] tmpSIOVREF__SineWave_net;

	cy_psoc3_pins_v1_10
		#(.id("77715107-f8d5-47e5-a629-0fb83101ac6b"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SineWave
		 (.oe(tmpOE__SineWave_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__SineWave_net[0:0]}),
		  .analog({Net_663}),
		  .io({tmpIO_0__SineWave_net[0:0]}),
		  .siovref(tmpSIOVREF__SineWave_net),
		  .interrupt({tmpINTERRUPT_0__SineWave_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SineWave_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Song2Trigger_net;
	wire [0:0] tmpFB_0__Song2Trigger_net;
	wire [0:0] tmpINTERRUPT_0__Song2Trigger_net;
	electrical [0:0] tmpSIOVREF__Song2Trigger_net;

	cy_psoc3_pins_v1_10
		#(.id("c7112de1-379d-43d4-af50-495b1d71881a"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Song2Trigger
		 (.oe(tmpOE__Song2Trigger_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Song2Trigger_net[0:0]}),
		  .io({Net_1183}),
		  .siovref(tmpSIOVREF__Song2Trigger_net),
		  .interrupt({tmpINTERRUPT_0__Song2Trigger_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Song2Trigger_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Song1Trigger_net;
	wire [0:0] tmpFB_0__Song1Trigger_net;
	wire [0:0] tmpINTERRUPT_0__Song1Trigger_net;
	electrical [0:0] tmpSIOVREF__Song1Trigger_net;

	cy_psoc3_pins_v1_10
		#(.id("8d318d8b-cf7b-4b6b-b02c-ab1c5c49d0ba"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Song1Trigger
		 (.oe(tmpOE__Song1Trigger_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Song1Trigger_net[0:0]}),
		  .io({Net_1184}),
		  .siovref(tmpSIOVREF__Song1Trigger_net),
		  .interrupt({tmpINTERRUPT_0__Song1Trigger_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Song1Trigger_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    WaveDAC8_v2_10_2 SineWaveGen (
        .Wave(Net_661),
        .ws(Net_539),
        .clock(Net_540),
        .wc1(Net_1147),
        .wc2(Net_1148));

	wire [0:0] tmpOE__Song4Trigger_net;
	wire [0:0] tmpFB_0__Song4Trigger_net;
	wire [0:0] tmpINTERRUPT_0__Song4Trigger_net;
	electrical [0:0] tmpSIOVREF__Song4Trigger_net;

	cy_psoc3_pins_v1_10
		#(.id("c7a5b014-6128-4d60-9835-08d9a21dc372"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Song4Trigger
		 (.oe(tmpOE__Song4Trigger_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Song4Trigger_net[0:0]}),
		  .io({Net_1185}),
		  .siovref(tmpSIOVREF__Song4Trigger_net),
		  .interrupt({tmpINTERRUPT_0__Song4Trigger_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Song4Trigger_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Song3Trigger_net;
	wire [0:0] tmpFB_0__Song3Trigger_net;
	wire [0:0] tmpINTERRUPT_0__Song3Trigger_net;
	electrical [0:0] tmpSIOVREF__Song3Trigger_net;

	cy_psoc3_pins_v1_10
		#(.id("76ddbfb8-d368-43e0-98de-8faab2ef946c"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Song3Trigger
		 (.oe(tmpOE__Song3Trigger_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Song3Trigger_net[0:0]}),
		  .io({Net_1186}),
		  .siovref(tmpSIOVREF__Song3Trigger_net),
		  .interrupt({tmpINTERRUPT_0__Song3Trigger_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Song3Trigger_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    CharLCD_v2_20_3 LCD_Char_1 ();

    VDAC8_v1_90_4 VDAC8_1 (
        .strobe(1'b0),
        .data(8'b00000000),
        .vOut(Net_697));
    defparam VDAC8_1.Data_Source = 0;
    defparam VDAC8_1.Initial_Value = 25;
    defparam VDAC8_1.Strobe_Mode = 0;

	wire [0:0] tmpOE__ADC_Positive_Input_net;
	wire [0:0] tmpFB_0__ADC_Positive_Input_net;
	wire [0:0] tmpIO_0__ADC_Positive_Input_net;
	wire [0:0] tmpINTERRUPT_0__ADC_Positive_Input_net;
	electrical [0:0] tmpSIOVREF__ADC_Positive_Input_net;

	cy_psoc3_pins_v1_10
		#(.id("90511d17-bdc7-4fc4-bce4-bc76d9968db3"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		ADC_Positive_Input
		 (.oe(tmpOE__ADC_Positive_Input_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__ADC_Positive_Input_net[0:0]}),
		  .analog({Net_685}),
		  .io({tmpIO_0__ADC_Positive_Input_net[0:0]}),
		  .siovref(tmpSIOVREF__ADC_Positive_Input_net),
		  .interrupt({tmpINTERRUPT_0__ADC_Positive_Input_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__ADC_Positive_Input_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ADC_DelSig_v3_20_5 ADC (
        .vplus(Net_685),
        .vminus(Net_1159),
        .soc(1'b1),
        .eoc(Net_688),
        .aclk(1'b0),
        .nVref(Net_690),
        .mi(1'b0));

    PGA_v2_0_6 PGA (
        .Vin(Net_661),
        .Vref(Net_675),
        .Vout(Net_663));

	wire [0:0] tmpOE__SensorValue2_net;
	wire [0:0] tmpFB_0__SensorValue2_net;
	wire [0:0] tmpIO_0__SensorValue2_net;
	wire [0:0] tmpINTERRUPT_0__SensorValue2_net;
	electrical [0:0] tmpSIOVREF__SensorValue2_net;

	cy_psoc3_pins_v1_10
		#(.id("73e43ec7-89db-4130-9728-8b03ae93336e"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SensorValue2
		 (.oe(tmpOE__SensorValue2_net),
		  .y({Net_1193}),
		  .fb({tmpFB_0__SensorValue2_net[0:0]}),
		  .io({tmpIO_0__SensorValue2_net[0:0]}),
		  .siovref(tmpSIOVREF__SensorValue2_net),
		  .interrupt({tmpINTERRUPT_0__SensorValue2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SensorValue2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__SensorValue4_net;
	wire [0:0] tmpFB_0__SensorValue4_net;
	wire [0:0] tmpIO_0__SensorValue4_net;
	wire [0:0] tmpINTERRUPT_0__SensorValue4_net;
	electrical [0:0] tmpSIOVREF__SensorValue4_net;

	cy_psoc3_pins_v1_10
		#(.id("ba9b4f86-0986-44ba-a3df-c35783e95a9a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SensorValue4
		 (.oe(tmpOE__SensorValue4_net),
		  .y({Net_1195}),
		  .fb({tmpFB_0__SensorValue4_net[0:0]}),
		  .io({tmpIO_0__SensorValue4_net[0:0]}),
		  .siovref(tmpSIOVREF__SensorValue4_net),
		  .interrupt({tmpINTERRUPT_0__SensorValue4_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SensorValue4_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Sensor_Interrupt_net;
	wire [0:0] tmpFB_0__Sensor_Interrupt_net;
	wire [0:0] tmpIO_0__Sensor_Interrupt_net;
	wire [0:0] tmpINTERRUPT_0__Sensor_Interrupt_net;
	electrical [0:0] tmpSIOVREF__Sensor_Interrupt_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Sensor_Interrupt
		 (.oe(tmpOE__Sensor_Interrupt_net),
		  .y({Net_1178}),
		  .fb({tmpFB_0__Sensor_Interrupt_net[0:0]}),
		  .io({tmpIO_0__Sensor_Interrupt_net[0:0]}),
		  .siovref(tmpSIOVREF__Sensor_Interrupt_net),
		  .interrupt({tmpINTERRUPT_0__Sensor_Interrupt_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Sensor_Interrupt_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__SensorValue5_net;
	wire [0:0] tmpFB_0__SensorValue5_net;
	wire [0:0] tmpIO_0__SensorValue5_net;
	wire [0:0] tmpINTERRUPT_0__SensorValue5_net;
	electrical [0:0] tmpSIOVREF__SensorValue5_net;

	cy_psoc3_pins_v1_10
		#(.id("820e4c4f-67c4-4e53-abae-cfb0309c3355"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SensorValue5
		 (.oe(tmpOE__SensorValue5_net),
		  .y({Net_1196}),
		  .fb({tmpFB_0__SensorValue5_net[0:0]}),
		  .io({tmpIO_0__SensorValue5_net[0:0]}),
		  .siovref(tmpSIOVREF__SensorValue5_net),
		  .interrupt({tmpINTERRUPT_0__SensorValue5_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SensorValue5_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__SensorValue3_net;
	wire [0:0] tmpFB_0__SensorValue3_net;
	wire [0:0] tmpIO_0__SensorValue3_net;
	wire [0:0] tmpINTERRUPT_0__SensorValue3_net;
	electrical [0:0] tmpSIOVREF__SensorValue3_net;

	cy_psoc3_pins_v1_10
		#(.id("e027cdcc-e16c-40f9-a44e-83cfea02ada3"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SensorValue3
		 (.oe(tmpOE__SensorValue3_net),
		  .y({Net_1194}),
		  .fb({tmpFB_0__SensorValue3_net[0:0]}),
		  .io({tmpIO_0__SensorValue3_net[0:0]}),
		  .siovref(tmpSIOVREF__SensorValue3_net),
		  .interrupt({tmpINTERRUPT_0__SensorValue3_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SensorValue3_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Sensor5_net;
	wire [0:0] tmpFB_0__Sensor5_net;
	wire [0:0] tmpIO_0__Sensor5_net;
	wire [0:0] tmpINTERRUPT_0__Sensor5_net;
	electrical [0:0] tmpSIOVREF__Sensor5_net;

	cy_psoc3_pins_v1_10
		#(.id("9ada4291-4048-473c-90df-7655a3329554"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Sensor5
		 (.oe(tmpOE__Sensor5_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Sensor5_net[0:0]}),
		  .analog({Net_1262}),
		  .io({tmpIO_0__Sensor5_net[0:0]}),
		  .siovref(tmpSIOVREF__Sensor5_net),
		  .interrupt({tmpINTERRUPT_0__Sensor5_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Sensor5_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Sensor4_net;
	wire [0:0] tmpFB_0__Sensor4_net;
	wire [0:0] tmpIO_0__Sensor4_net;
	wire [0:0] tmpINTERRUPT_0__Sensor4_net;
	electrical [0:0] tmpSIOVREF__Sensor4_net;

	cy_psoc3_pins_v1_10
		#(.id("d91baebc-2206-4ae4-a06c-1b9cee01cab6"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Sensor4
		 (.oe(tmpOE__Sensor4_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Sensor4_net[0:0]}),
		  .analog({Net_1260}),
		  .io({tmpIO_0__Sensor4_net[0:0]}),
		  .siovref(tmpSIOVREF__Sensor4_net),
		  .interrupt({tmpINTERRUPT_0__Sensor4_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Sensor4_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Sensor3_net;
	wire [0:0] tmpFB_0__Sensor3_net;
	wire [0:0] tmpIO_0__Sensor3_net;
	wire [0:0] tmpINTERRUPT_0__Sensor3_net;
	electrical [0:0] tmpSIOVREF__Sensor3_net;

	cy_psoc3_pins_v1_10
		#(.id("434438af-4166-4c10-b0f5-a2ab466ca16a"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Sensor3
		 (.oe(tmpOE__Sensor3_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Sensor3_net[0:0]}),
		  .analog({Net_1259}),
		  .io({tmpIO_0__Sensor3_net[0:0]}),
		  .siovref(tmpSIOVREF__Sensor3_net),
		  .interrupt({tmpINTERRUPT_0__Sensor3_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Sensor3_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Sensor2_net;
	wire [0:0] tmpFB_0__Sensor2_net;
	wire [0:0] tmpIO_0__Sensor2_net;
	wire [0:0] tmpINTERRUPT_0__Sensor2_net;
	electrical [0:0] tmpSIOVREF__Sensor2_net;

	cy_psoc3_pins_v1_10
		#(.id("be15b11f-1c8c-4d8f-a596-8ec2fb6525ba"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Sensor2
		 (.oe(tmpOE__Sensor2_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Sensor2_net[0:0]}),
		  .analog({Net_1257}),
		  .io({tmpIO_0__Sensor2_net[0:0]}),
		  .siovref(tmpSIOVREF__Sensor2_net),
		  .interrupt({tmpINTERRUPT_0__Sensor2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Sensor2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ScanComp_v1_10_8 SensorScan (
        .clock(1'b0),
        .interrupt(Net_1178),
        .eos(Net_1192),
        .CmpOut0(Net_1190),
        .CmpOut1(Net_1193),
        .CmpOut2(Net_1194),
        .CmpOut3(Net_1195),
        .CmpOut4(Net_1196),
        .CmpOut5(Net_1197),
        .CmpOut6(Net_1198),
        .CmpOut7(Net_1199),
        .CmpOut8(Net_1200),
        .CmpOut9(Net_1201),
        .CmpOut10(Net_1202),
        .CmpOut11(Net_1203),
        .CmpOut12(Net_1204),
        .CmpOut13(Net_1205),
        .CmpOut14(Net_1206),
        .CmpOut15(Net_1207),
        .CmpOut16(Net_1208),
        .CmpOut17(Net_1209),
        .CmpOut18(Net_1210),
        .CmpOut19(Net_1211),
        .CmpOut20(Net_1212),
        .CmpOut21(Net_1213),
        .CmpOut22(Net_1214),
        .CmpOut23(Net_1215),
        .CmpOut24(Net_1216),
        .CmpOut25(Net_1217),
        .CmpOut26(Net_1218),
        .CmpOut27(Net_1219),
        .CmpOut28(Net_1220),
        .CmpOut29(Net_1221),
        .CmpOut30(Net_1222),
        .CmpOut31(Net_1223),
        .CmpOut32(Net_1224),
        .CmpOut33(Net_1225),
        .CmpOut34(Net_1226),
        .CmpOut35(Net_1227),
        .CmpOut36(Net_1228),
        .CmpOut37(Net_1229),
        .CmpOut38(Net_1230),
        .CmpOut39(Net_1231),
        .CmpOut40(Net_1232),
        .CmpOut41(Net_1233),
        .CmpOut42(Net_1234),
        .CmpOut43(Net_1235),
        .CmpOut44(Net_1236),
        .CmpOut45(Net_1237),
        .CmpOut46(Net_1238),
        .CmpOut47(Net_1239),
        .CmpOut48(Net_1240),
        .CmpOut49(Net_1241),
        .CmpOut50(Net_1242),
        .CmpOut51(Net_1243),
        .CmpOut52(Net_1244),
        .CmpOut53(Net_1245),
        .CmpOut54(Net_1246),
        .CmpOut55(Net_1247),
        .CmpOut56(Net_1248),
        .CmpOut57(Net_1249),
        .CmpOut58(Net_1250),
        .CmpOut59(Net_1251),
        .CmpOut60(Net_1252),
        .CmpOut61(Net_1253),
        .CmpOut62(Net_1254),
        .CmpOut63(Net_1255),
        .AIN_10(Net_1189),
        .AIN_11(Net_1256),
        .AIN1(Net_1257),
        .AIN_20(Net_1258),
        .AIN_21(Net_1259),
        .AIN_30(Net_1260),
        .AIN_31(Net_1261),
        .AIN3(Net_1262),
        .AIN_40(Net_1263),
        .AIN_41(Net_1264),
        .AIN_50(Net_1265),
        .AIN_51(Net_1266),
        .AIN5(Net_1267),
        .AIN_60(Net_1268),
        .AIN_61(Net_1269),
        .AIN_70(Net_1270),
        .AIN_71(Net_1271),
        .AIN7(Net_1272),
        .AIN_80(Net_1273),
        .AIN_81(Net_1274),
        .AIN_90(Net_1275),
        .AIN_91(Net_1276),
        .AIN9(Net_1277),
        .AIN_100(Net_1278),
        .AIN_101(Net_1279),
        .AIN_110(Net_1280),
        .AIN_111(Net_1281),
        .AIN11(Net_1282),
        .AIN_120(Net_1283),
        .AIN_121(Net_1284),
        .AIN_130(Net_1285),
        .AIN_131(Net_1286),
        .AIN13(Net_1287),
        .AIN_140(Net_1288),
        .AIN_141(Net_1289),
        .AIN_150(Net_1290),
        .AIN_151(Net_1291),
        .AIN15(Net_1292),
        .AIN_160(Net_1293),
        .AIN_161(Net_1294),
        .AIN_170(Net_1295),
        .AIN_171(Net_1296),
        .AIN17(Net_1297),
        .AIN_180(Net_1298),
        .AIN_181(Net_1299),
        .AIN_190(Net_1300),
        .AIN_191(Net_1301),
        .AIN19(Net_1302),
        .AIN_200(Net_1303),
        .AIN_201(Net_1304),
        .AIN_210(Net_1305),
        .AIN_211(Net_1306),
        .AIN21(Net_1307),
        .AIN_220(Net_1308),
        .AIN_221(Net_1309),
        .AIN_230(Net_1310),
        .AIN_231(Net_1311),
        .AIN23(Net_1312),
        .AIN_240(Net_1313),
        .AIN_241(Net_1314),
        .AIN_250(Net_1315),
        .AIN_251(Net_1316),
        .AIN25(Net_1317),
        .AIN_260(Net_1318),
        .AIN_261(Net_1319),
        .AIN_270(Net_1320),
        .AIN_271(Net_1321),
        .AIN27(Net_1322),
        .AIN_280(Net_1323),
        .AIN_281(Net_1324),
        .AIN_290(Net_1325),
        .AIN_291(Net_1326),
        .AIN29(Net_1327),
        .AIN_300(Net_1328),
        .AIN_301(Net_1329),
        .AIN_310(Net_1330),
        .AIN_311(Net_1331),
        .AIN31(Net_1332),
        .AIN_320(Net_1333),
        .AIN_321(Net_1334),
        .AIN_450(Net_1335),
        .AIN_451(Net_1336),
        .AIN_460(Net_1337),
        .AIN_461(Net_1338),
        .AIN_470(Net_1339),
        .AIN_471(Net_1340),
        .AIN_480(Net_1341),
        .AIN_481(Net_1342),
        .AIN_490(Net_1343),
        .AIN_491(Net_1344),
        .AIN_500(Net_1345),
        .AIN_501(Net_1346),
        .AIN_510(Net_1347),
        .AIN_511(Net_1348),
        .AIN_520(Net_1349),
        .AIN_521(Net_1350),
        .AIN_330(Net_1351),
        .AIN_331(Net_1352),
        .AIN33(Net_1353),
        .AIN_340(Net_1354),
        .AIN_341(Net_1355),
        .AIN_350(Net_1356),
        .AIN_351(Net_1357),
        .AIN35(Net_1358),
        .AIN_360(Net_1359),
        .AIN_361(Net_1360),
        .AIN_370(Net_1361),
        .AIN_371(Net_1362),
        .AIN37(Net_1363),
        .AIN_380(Net_1364),
        .AIN_381(Net_1365),
        .AIN_390(Net_1366),
        .AIN_391(Net_1367),
        .AIN39(Net_1368),
        .AIN_400(Net_1369),
        .AIN_401(Net_1370),
        .AIN_410(Net_1371),
        .AIN_411(Net_1372),
        .AIN41(Net_1373),
        .AIN_420(Net_1374),
        .AIN_421(Net_1375),
        .AIN_430(Net_1376),
        .AIN_431(Net_1377),
        .AIN_440(Net_1378),
        .AIN_441(Net_1379),
        .AIN_530(Net_1380),
        .AIN_531(Net_1381),
        .AIN_540(Net_1382),
        .AIN_541(Net_1383),
        .AIN_550(Net_1384),
        .AIN_551(Net_1385),
        .AIN_560(Net_1386),
        .AIN_561(Net_1387),
        .AIN_570(Net_1388),
        .AIN_571(Net_1389),
        .AIN_580(Net_1390),
        .AIN_581(Net_1391),
        .AIN_590(Net_1392),
        .AIN_591(Net_1393),
        .AIN_600(Net_1394),
        .AIN_601(Net_1395),
        .AIN_610(Net_1396),
        .AIN_611(Net_1397),
        .AIN_620(Net_1398),
        .AIN_621(Net_1399),
        .AIN_630(Net_1400),
        .AIN_631(Net_1401),
        .AIN_640(Net_1402),
        .AIN_641(Net_1403),
        .Vminus(Net_697));
    defparam SensorScan.OutputsEnable = 1;
    defparam SensorScan.SequencedChannels = 5;

	wire [0:0] tmpOE__SensorValue1_net;
	wire [0:0] tmpFB_0__SensorValue1_net;
	wire [0:0] tmpIO_0__SensorValue1_net;
	wire [0:0] tmpINTERRUPT_0__SensorValue1_net;
	electrical [0:0] tmpSIOVREF__SensorValue1_net;

	cy_psoc3_pins_v1_10
		#(.id("51c8157d-7dbe-488f-876c-462b4eecbdbc"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SensorValue1
		 (.oe(tmpOE__SensorValue1_net),
		  .y({Net_1190}),
		  .fb({tmpFB_0__SensorValue1_net[0:0]}),
		  .io({tmpIO_0__SensorValue1_net[0:0]}),
		  .siovref(tmpSIOVREF__SensorValue1_net),
		  .interrupt({tmpINTERRUPT_0__SensorValue1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SensorValue1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Sensor1_net;
	wire [0:0] tmpFB_0__Sensor1_net;
	wire [0:0] tmpIO_0__Sensor1_net;
	wire [0:0] tmpINTERRUPT_0__Sensor1_net;
	electrical [0:0] tmpSIOVREF__Sensor1_net;

	cy_psoc3_pins_v1_10
		#(.id("a6825cd6-806a-4d1c-ba04-d83f77ef91ab"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Sensor1
		 (.oe(tmpOE__Sensor1_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Sensor1_net[0:0]}),
		  .analog({Net_1189}),
		  .io({tmpIO_0__Sensor1_net[0:0]}),
		  .siovref(tmpSIOVREF__Sensor1_net),
		  .interrupt({tmpINTERRUPT_0__Sensor1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Sensor1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};



endmodule

