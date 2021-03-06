#
# Copyright (C) 2005-2020 Centre National d'Etudes Spatiales (CNES)
#
# This file is part of Orfeo Toolbox
#
#     https://www.orfeo-toolbox.org/
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

otb_module_test()

set(OTBMetadataTests
otbMetadataTestDriver.cxx
otbSarImageMetadataInterfaceTest.cxx
otbImageMetadataInterfaceBaseTest.cxx
otbSarDefaultImageMetadataInterface.cxx
otbOpticalImageMetadataInterfaceTest.cxx
otbOpticalDefaultImageMetadataInterface.cxx
otbDefaultImageMetadataInterface.cxx
otbImageMetadataInterfaceTest.cxx
otbImageMetadataInterfaceTest2.cxx
otbNoDataHelperTest.cxx
otbSarCalibrationLookupDataTest.cxx
otbImageMetadataTest.cxx
otbGeomMetadataSupplierTest.cxx
otbXMLMetadataSupplierTest.cxx
)

add_executable(otbMetadataTestDriver ${OTBMetadataTests})
target_link_libraries(otbMetadataTestDriver ${OTBMetadata-Test_LIBRARIES})
otb_module_target_label(otbMetadataTestDriver)

# Tests Declaration

#otb_add_test(NAME ioTvSarImageMetadataInterfaceTest_TSX1dims COMMAND otbMetadataTestDriver
  #--compare-ascii ${EPSILON_9} ${BASELINE_FILES}/ioTvSarImageMetadataInterface_TSX1dims.txt
  #${TEMP}/ioTvSarImageMetadataInterface_TSX1dims.txt
  #otbSarImageMetadataInterfaceTest
  #LARGEINPUT{TERRASARX/dims/TSX-1.SAR.L1B/TSX1_SAR__SSC/IMAGEDATA/IMAGE_HH_SRA_strip_011.cos}
  #${TEMP}/ioTvSarImageMetadataInterface_TSX1dims.txt
  #)

#otb_add_test(NAME ioTvSarImageMetadataInterfaceTest_TSX1PANGKALANBUUNUsingVVCosFile COMMAND otbMetadataTestDriver
  #--compare-ascii ${EPSILON_9} ${BASELINE_FILES}/ioTvSarImageMetadataInterface_TSX1PANGKALANBUUNUsingVVCosFile.txt
  #${TEMP}/ioTvSarImageMetadataInterface_TSX1PANGKALANBUUNUsingVVCosFile.txt
  #otbSarImageMetadataInterfaceTest
  #LARGEINPUT{TERRASARX/PANGKALANBUUN/IMAGEDATA/IMAGE_VV_SRA_stripFar_008.cos}
  #${TEMP}/ioTvSarImageMetadataInterface_TSX1PANGKALANBUUNUsingVVCosFile.txt
  #)

#otb_add_test(NAME ioTvSarImageMetadataInterfaceTest_TSX1TORONTO COMMAND otbMetadataTestDriver
  #--compare-ascii ${EPSILON_9} ${BASELINE_FILES}/ioTvSarImageMetadataInterface_TSX1TORONTO.txt
  #${TEMP}/ioTvSarImageMetadataInterface_TSX1TORONTO.txt
  #otbSarImageMetadataInterfaceTest
  #LARGEINPUT{TERRASARX/TORONTO/TSX1_SAR__SSC/IMAGEDATA/IMAGE_HH_SRA_spot_074.cos}
  #${TEMP}/ioTvSarImageMetadataInterface_TSX1TORONTO.txt
  #)

#otb_add_test(NAME ioTvSarImageMetadataInterfaceTest_TSX1PANGKALANBUUNUsingXmlFile COMMAND otbMetadataTestDriver
  #--compare-ascii ${EPSILON_9} ${BASELINE_FILES}/ioTvSarImageMetadataInterface_TSX1PangkalanbuunuUsingXmlFile.txt
  #${TEMP}/ioTvSarImageMetadataInterface_TSX1PangkalanbuunuUsingXmlFile.txt
  #otbSarImageMetadataInterfaceTest
  #LARGEINPUT{TERRASARX/PANGKALANBUUN/TSX1_SAR__SSC______SM_D_SRA_20080313T221955_20080313T222003.xml}
  #${TEMP}/ioTvSarImageMetadataInterface_TSX1PangkalanbuunuUsingXmlFile.txt
  #)

#otb_add_test(NAME ioTvSarImageMetadataInterfaceTest_TSX1PANGKALANBUUNUsingHHCosFile COMMAND otbMetadataTestDriver
  #--compare-ascii ${EPSILON_9} ${BASELINE_FILES}/ioTvSarImageMetadataInterface_TSX1PANGKALANBUUNUsingHHCosFile.txt
  #${TEMP}/ioTvSarImageMetadataInterface_TSX1PANGKALANBUUNUsingHHCosFile.txt
  #otbSarImageMetadataInterfaceTest
  #LARGEINPUT{TERRASARX/PANGKALANBUUN/IMAGEDATA/IMAGE_HH_SRA_stripFar_008.cos}
  #${TEMP}/ioTvSarImageMetadataInterface_TSX1PANGKALANBUUNUsingHHCosFile.txt
  #)

#otb_add_test(NAME ioTvSentinel1ImageMetadataInterfaceTest COMMAND otbMetadataTestDriver
#  otbSentinel1ImageMetadataInterfaceTest
#  /home/julien/Bureau/S1Product/S1A_IW_GRDH_1SDV_20170819T001029_20170819T001054_017985_01E2E8_F302.SAFE
#  ${TEMP}/ioTvSentinel1ImageMetadataInterfaceTest.txt
#  )

#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_SENTINEL1 COMMAND otbMetadataTestDriver
  #--compare-ascii ${EPSILON_9} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_SENTINEL1.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_SENTINEL1.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{SENTINEL1/S1A_S6_SLC__1SSV_20150619T195043/measurement/s1a-s6-slc-vv-20150619t195043-20150619t195101-006447-00887d-001.tiff}
  #${TEMP}/ioTvImageMetadataInterfaceBase_SENTINEL1.txt
  #)

#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_RADARSAT2 COMMAND otbMetadataTestDriver
  #--compare-ascii ${EPSILON_9} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_RADARSAT2.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_RADARSAT2.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{RADARSAT2/ALTONA/Fine_Quad-Pol_Dataset/PK6621_DK406_FQ9_20080405_124900_HH_VV_HV_VH_SLC_Altona/imagery_HV.tif}
  #${TEMP}/ioTvImageMetadataInterfaceBase_RADARSAT2.txt
  #)


#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_SPOT COMMAND otbMetadataTestDriver
  #--compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_SPOT.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_SPOT.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{SPOT5/TEHERAN/IMAGERY.TIF}
  #${TEMP}/ioTvImageMetadataInterfaceBase_SPOT.txt
  #)

#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_TSX1PANGKALANBUUNUsingVVCosFile COMMAND otbMetadataTestDriver
  #--compare-ascii ${EPSILON_9} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_TSX1PANGKALANBUUNUsingVVCosFile.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_TSX1PANGKALANBUUNUsingVVCosFile.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{TERRASARX/PANGKALANBUUN/IMAGEDATA/IMAGE_VV_SRA_stripFar_008.cos}
  #${TEMP}/ioTvImageMetadataInterfaceBase_TSX1PANGKALANBUUNUsingVVCosFile.txt
  #)

#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_TSX1PANGKALANBUUNUsingHHCosFile COMMAND otbMetadataTestDriver
  #--compare-ascii ${EPSILON_9} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_TSX1PANGKALANBUUNUsingHHCosFile.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_TSX1PANGKALANBUUNUsingHHCosFile.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{TERRASARX/PANGKALANBUUN/IMAGEDATA/IMAGE_HH_SRA_stripFar_008.cos}
  #${TEMP}/ioTvImageMetadataInterfaceBase_TSX1PANGKALANBUUNUsingHHCosFile.txt
  #)

#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_FORMOSAT2 COMMAND otbMetadataTestDriver
  #--compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_FORMOSAT2.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_FORMOSAT2.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{FORMOSAT/Sudouest_20071013_MS_fmsat/IMAGERY.TIF}
  #${TEMP}/ioTvImageMetadataInterfaceBase_FORMOSAT2.txt
  #)

#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_TSX1dims COMMAND otbMetadataTestDriver
  #--compare-ascii ${EPSILON_9} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_TSX1dims.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_TSX1dims.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{TERRASARX/dims/TSX-1.SAR.L1B/TSX1_SAR__SSC/IMAGEDATA/IMAGE_HH_SRA_strip_011.cos}
  #${TEMP}/ioTvImageMetadataInterfaceBase_TSX1dims.txt
  #)

#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_QBMUL COMMAND otbMetadataTestDriver
  #--compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_QBMUL.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_QBMUL.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{QUICKBIRD/TOULOUSE/000000128955_01_P001_MUL/02APR01105228-M1BS-000000128955_01_P001.TIF}
  #${TEMP}/ioTvImageMetadataInterfaceBase_QBMUL.txt
  #)

#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_WV2Mul COMMAND otbMetadataTestDriver
  #--compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_WV2RomeMul.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_WV2RomeMul.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{WORLDVIEW2/ROME/WV-2_standard_8band_bundle_16bit/052298844010_01_P001_MUL/09DEC10103019-M2AS-052298844010_01_P001.TIF}
  #${TEMP}/ioTvImageMetadataInterfaceBase_WV2RomeMul.txt
  #)

#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_QB COMMAND otbMetadataTestDriver
  #--compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_QB.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_QB.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{QUICKBIRD/TOULOUSE/000000128955_01_P001_PAN/02APR01105228-P1BS-000000128955_01_P001.TIF}
  #${TEMP}/ioTvImageMetadataInterfaceBase_QB.txt
  #)

#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_WV2Pan COMMAND otbMetadataTestDriver
  #--compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_WV2RomePan.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_WV2RomePan.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{WORLDVIEW2/ROME/WV-2_standard_8band_bundle_16bit/052298844010_01_P001_PAN/09DEC10103019-P2AS-052298844010_01_P001.TIF}
  #${TEMP}/ioTvImageMetadataInterfaceBase_WV2RomePan.txt
  #)

#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_IKONOS COMMAND otbMetadataTestDriver
  #--compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_IKONOS.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_IKONOS.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{IKONOS/BLOSSEVILLE/po_2619900_blu_0000000.tif}
  #${TEMP}/ioTvImageMetadataInterfaceBase_IKONOS.txt
  #)

#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_TSX1PANGKALANBUUNUsingXmlFile COMMAND otbMetadataTestDriver
  #--compare-ascii ${EPSILON_9} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_TSX1PangkalanbuunuUsingXmlFile.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_TSX1PangkalanbuunuUsingXmlFile.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{TERRASARX/PANGKALANBUUN/TSX1_SAR__SSC______SM_D_SRA_20080313T221955_20080313T222003.xml}
  #${TEMP}/ioTvImageMetadataInterfaceBase_TSX1PangkalanbuunuUsingXmlFile.txt
  #)

#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_QBCevennes COMMAND otbMetadataTestDriver
  #--compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_QBCevennes.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_QBCevennes.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{QUICKBIRD/CEVENNES/06FEB12104912-P1BS-005533998070_01_P001.TIF}
  #${TEMP}/ioTvImageMetadataInterfaceBase_QBCevennes.txt
  #)

#otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_TSX1TORONTO COMMAND otbMetadataTestDriver
  #--compare-ascii ${EPSILON_9} ${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_TSX1TORONTO.txt
  #${TEMP}/ioTvImageMetadataInterfaceBase_TSX1TORONTO.txt
  #otbImageMetadataInterfaceBaseTest
  #LARGEINPUT{TERRASARX/TORONTO/TSX1_SAR__SSC/IMAGEDATA/IMAGE_HH_SRA_spot_074.cos}
  #${TEMP}/ioTvImageMetadataInterfaceBase_TSX1TORONTO.txt
  #)

otb_add_test(NAME ioTuSarDefaultImageMetadataInterface COMMAND otbMetadataTestDriver
  otbSarDefaultImageMetadataInterface )

otb_add_test(NAME ioTvOpticalImageMetadataInterfaceTest_QBCevennes COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvOpticalImageMetadataInterface_QBCevennes.txt
  ${TEMP}/ioTvOpticalImageMetadataInterface_QBCevennes.txt
  otbOpticalImageMetadataInterfaceTest
  LARGEINPUT{QUICKBIRD/CEVENNES/06FEB12104912-P1BS-005533998070_01_P001.TIF}
  ${TEMP}/ioTvOpticalImageMetadataInterface_QBCevennes.txt
  )

otb_add_test(NAME ioTvOpticalImageMetadataInterfaceTest_WV2Pan COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvOpticalImageMetadataInterface_WV2RomePan.txt
  ${TEMP}/ioTvOpticalImageMetadataInterface_WV2RomePan.txt
  otbOpticalImageMetadataInterfaceTest
  LARGEINPUT{WORLDVIEW2/ROME/WV-2_standard_8band_bundle_16bit/052298844010_01_P001_PAN/09DEC10103019-P2AS-052298844010_01_P001.TIF}
  ${TEMP}/ioTvOpticalImageMetadataInterface_WV2RomePan.txt
  )

otb_add_test(NAME ioTvOpticalImageMetadataInterfaceTest_QBMUL COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvOpticalImageMetadataInterface_QBMUL.txt
  ${TEMP}/ioTvOpticalImageMetadataInterface_QBMUL.txt
  otbOpticalImageMetadataInterfaceTest
  LARGEINPUT{QUICKBIRD/TOULOUSE/000000128955_01_P001_MUL/02APR01105228-M1BS-000000128955_01_P001.TIF}
  ${TEMP}/ioTvOpticalImageMetadataInterface_QBMUL.txt
  )

otb_add_test(NAME ioTvOpticalImageMetadataInterfaceTest_WV2Mul COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvOpticalImageMetadataInterface_WV2RomeMul.txt
  ${TEMP}/ioTvOpticalImageMetadataInterface_WV2RomeMul.txt
  otbOpticalImageMetadataInterfaceTest
  LARGEINPUT{WORLDVIEW2/ROME/WV-2_standard_8band_bundle_16bit/052298844010_01_P001_MUL/09DEC10103019-M2AS-052298844010_01_P001.TIF}
  ${TEMP}/ioTvOpticalImageMetadataInterface_WV2RomeMul.txt
  )

otb_add_test(NAME ioTvOpticalImageMetadataInterfaceTest_SPOT COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvOpticalImageMetadataInterface_SPOT.txt
  ${TEMP}/ioTvOpticalImageMetadataInterface_SPOT.txt
  otbOpticalImageMetadataInterfaceTest
  LARGEINPUT{SPOT5/TEHERAN/IMAGERY.TIF}
  ${TEMP}/ioTvOpticalImageMetadataInterface_SPOT.txt
  )

otb_add_test(NAME ioTvOpticalImageMetadataInterfaceTest_QB COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvOpticalImageMetadataInterface_QB.txt
  ${TEMP}/ioTvOpticalImageMetadataInterface_QB.txt
  otbOpticalImageMetadataInterfaceTest
  LARGEINPUT{QUICKBIRD/TOULOUSE/000000128955_01_P001_PAN/02APR01105228-P1BS-000000128955_01_P001.TIF}
  ${TEMP}/ioTvOpticalImageMetadataInterface_QB.txt
  )

otb_add_test(NAME ioTvOpticalImageMetadataInterfaceTest_IKONOS COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvOpticalImageMetadataInterface_IKONOS.txt
  ${TEMP}/ioTvOpticalImageMetadataInterface_IKONOS.txt
  otbOpticalImageMetadataInterfaceTest
  LARGEINPUT{IKONOS/BLOSSEVILLE/po_2619900_blu_0000000.tif}
  ${TEMP}/ioTvOpticalImageMetadataInterface_IKONOS.txt
  )

otb_add_test(NAME ioTvOpticalImageMetadataInterfaceTest_FORMOSAT2 COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvOpticalImageMetadataInterface_FORMOSAT2.txt
  ${TEMP}/ioTvOpticalImageMetadataInterface_FORMOSAT2.txt
  otbOpticalImageMetadataInterfaceTest
  LARGEINPUT{FORMOSAT/Sudouest_20071013_MS_fmsat/IMAGERY.TIF}
  ${TEMP}/ioTvOpticalImageMetadataInterface_FORMOSAT2.txt
  )


otb_add_test(NAME ioTuOpticalDefaultImageMetadataInterface COMMAND otbMetadataTestDriver
  otbOpticalDefaultImageMetadataInterface )







otb_add_test(NAME ioTuDefaultImageMetadataInterface COMMAND otbMetadataTestDriver
  otbDefaultImageMetadataInterface )

otb_add_test(NAME ioTvImageMetadataInterfaceTest COMMAND otbMetadataTestDriver
  --compare-ascii ${EPSILON_9} ${BASELINE_FILES}/ioTvImageMetadataInterface.txt
  ${TEMP}/ioTvImageMetadataInterface.txt
  otbImageMetadataInterfaceTest2
  ${INPUTDATA}/qb_RoadExtract.tif
  ${TEMP}/ioTvImageMetadataInterface.txt
  )

set( GenericTestPHR_TESTNB 0)
foreach( current_file ${GenericTestPHR_DATA_INPUTS} )
  list(GET GenericTestPHR_DATA_TYPES   ${GenericTestPHR_TESTNB} current_type   )
  math(EXPR GenericTestPHR_TESTNB "${GenericTestPHR_TESTNB} + 1")

  #otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_${current_type} COMMAND otbMetadataTestDriver
    #--compare-ascii ${NOTOL}
      #${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_${current_type}.txt
      #${TEMP}/ioTvImageMetadataInterfaceBase_${current_type}_OUT.txt
    #otbImageMetadataInterfaceBaseTest
      #${current_file}
     #${TEMP}/ioTvImageMetadataInterfaceBase_${current_type}_OUT.txt
    #)

  otb_add_test(NAME ioTvOpticalImageMetadataInterfaceTest_${current_type} COMMAND otbMetadataTestDriver
    --compare-ascii ${NOTOL}
      ${BASELINE_FILES}/ioTvOpticalImageMetadataInterface_${current_type}.txt
      ${TEMP}/ioTvOpticalImageMetadataInterface_${current_type}_OUT.txt
    otbOpticalImageMetadataInterfaceTest
      ${current_file}
      ${TEMP}/ioTvOpticalImageMetadataInterface_${current_type}_OUT.txt
    )
endforeach()

# SPOT 6
set( GenericTestSPOT6_TESTNB 0)

foreach( current_file ${GenericTestSPOT6_DATA_INPUTS} )
  list(GET GenericTestSPOT6_DATA_TYPES   ${GenericTestSPOT6_TESTNB} current_type )
  math(EXPR GenericTestSPOT6_TESTNB "${GenericTestSPOT6_TESTNB} + 1")

  #otb_add_test(NAME ioTvImageMetadataInterfaceBaseTest_${current_type} COMMAND otbMetadataTestDriver
    #--compare-ascii ${NOTOL}
      #${BASELINE_FILES}/ioTvImageMetadataInterfaceBase_${current_type}.txt
      #${TEMP}/ioTvImageMetadataInterfaceBase_${current_type}_OUT.txt
    #otbImageMetadataInterfaceBaseTest
      #${current_file}
      #${TEMP}/ioTvImageMetadataInterfaceBase_${current_type}_OUT.txt
    #)

  otb_add_test(NAME ioTvOpticalImageMetadataInterfaceTest_${current_type} COMMAND otbMetadataTestDriver
    --compare-ascii ${NOTOL}
      ${BASELINE_FILES}/ioTvOpticalImageMetadataInterface_${current_type}.txt
      ${TEMP}/ioTvOpticalImageMetadataInterface_${current_type}_OUT.txt
    otbOpticalImageMetadataInterfaceTest
      ${current_file}
      ${TEMP}/ioTvOpticalImageMetadataInterface_${current_type}_OUT.txt
    )
endforeach()

otb_add_test(NAME coreMetaDataNoDataHelperTest COMMAND otbMetadataTestDriver
  otbNoDataHelperTest)

otb_add_test(NAME ioTvSarCalibrationLookupDataTest_SENTINEL1 COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvSarCalibrationLookupDataTest_SENTINEL1.txt
  ${TEMP}/ioTvSarCalibrationLookupDataTest_SENTINEL1.txt
  otbSarCalibrationLookupDataTest
  ${INPUTDATA}/SENTINEL1_SLC_S6_1S_extract_1200_1100_300_300.tiff?&geom=${INPUTDATA}/SENTINEL1_SLC_S6_1S_extract_1200_1100_300_300.geom
  ${TEMP}/ioTvSarCalibrationLookupDataTest_SENTINEL1.txt
  )

otb_add_test(NAME ioTvSarCalibrationLookupDataTest_RADARSAT2 COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTvSarCalibrationLookupDataTest_RADARSAT2.txt
  ${TEMP}/ioTvSarCalibrationLookupDataTest_RADARSAT2.txt
  otbSarCalibrationLookupDataTest
  ${INPUTDATA}/RADARSAT2_ALTONA_300_300_VV.tif?&geom=${INPUTDATA}/RADARSAT2_ALTONA_300_300_VV.geom
  ${TEMP}/ioTvSarCalibrationLookupDataTest_RADARSAT2.txt
  )

otb_add_test(NAME ioTuMetaDataKeyTest COMMAND otbMetadataTestDriver 
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTuMetaDataKeyTest.txt
  ${TEMP}/ioTuMetaDataKeyTest.txt
  otbImageMetadataTest
  otbMetadataKeyTest
  ${TEMP}/ioTuMetaDataKeyTest.txt
  )
  
otb_add_test(NAME ioTuImageMetadataSliceTest COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTuImageMetadataSliceTest.txt
  ${TEMP}/ioTuImageMetadataSliceTest.txt
  otbImageMetadataTest
  otbImageMetadataSliceTest
  ${TEMP}/ioTuImageMetadataSliceTest.txt
  )
  
otb_add_test(NAME ioTuImageMetadataCompactTest COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTuImageMetadataCompactTest.txt
  ${TEMP}/ioTuImageMetadataCompactTest.txt
  otbImageMetadataTest
  otbImageMetadataCompactTest
  ${TEMP}/ioTuImageMetadataCompactTest.txt
  )
  
otb_add_test(NAME ioTuImageMetadataAppendTest COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTuImageMetadataAppendTest.txt
  ${TEMP}/ioTuImageMetadataAppendTest.txt
  otbImageMetadataTest
  otbImageMetadataAppendTest
  ${TEMP}/ioTuImageMetadataAppendTest.txt
  )

otb_add_test(NAME ioTuImageMetadataMergeTest COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTuImageMetadataMergeTest.txt
  ${TEMP}/ioTuImageMetadataMergeTest.txt
  otbImageMetadataTest
  otbImageMetadataMergeTest
  ${TEMP}/ioTuImageMetadataMergeTest.txt
  )

otb_add_test(NAME ioTuImageMetadataToFromKeywordlistTest COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTuImageMetadataToFromKeywordlistTest.txt
  ${TEMP}/ioTuImageMetadataToFromKeywordlistTest.txt
  otbImageMetadataTest
  otbImageMetadataToFromKeywordlistTest
  ${TEMP}/ioTuImageMetadataToFromKeywordlistTest.txt
  )
  
otb_add_test(NAME ioTuotbGeomMetadataSupplierTest COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTuotbGeomMetadataSupplierTest.txt
  ${TEMP}/ioTuotbGeomMetadataSupplierTest.txt
  otbGeomMetadataSupplierTest
  ${INPUTDATA}/QB/qb-1.geom
  ${TEMP}/ioTuotbGeomMetadataSupplierTest.txt
  )
  
otb_add_test(NAME ioTuotbXMLMetadataSupplierTest COMMAND otbMetadataTestDriver
  --compare-ascii ${NOTOL} ${BASELINE_FILES}/ioTuotbXMLMetadataSupplierTest.txt
  ${TEMP}/ioTuotbXMLMetadataSupplierTest.txt
  otbXMLMetadataSupplierTest
  ${INPUTDATA}/ioTuotbXMLMetadataSupplierTest.xml
  ${TEMP}/ioTuotbXMLMetadataSupplierTest.txt
  )



# Image metadata interface tests.
# The image metadata are read from a product and dumped into a txt file, which is then compared 
# to a baseline ${BASELINE_FILES}/ioTvImageMetadataInterfaceTest_${sensor}.txt.
# To create a test, add the name of the sensor in "sensor list" and define the ${sensor}_filename variable.
# Additionally, it is possible to compare the metadata of the product with the metadata of a geom file
# with the --compare-metadata utility by setting ${sensor}_geom_file

set(sensor_list pleiades spot6 spot5 spot5_2 formosat ikonos worldview2 quickbird Radarsat2 TerraSar CosmoSkyMed Sentinel1)

set(pleiades_filename LARGEINPUT{PLEIADES/MAIDO_JP2_DIMAPv2_PRIMARY_MS_lossy_12bits/IMG_PHR1A_MS_002/IMG_PHR1A_MS_201206050630064_SEN_559102101-002_R1C1.JP2})
set(spot6_filename LARGEINPUT{SPOT6/600143101-Primary-Bundle-JP2-LOSSLESS/PROD_SPOT6_001/VOL_SPOT6_001_A/IMG_SPOT6_MS_001_A/IMG_SPOT6_MS_201212071020271_SEN_600143101_R1C1.JP2})
set(spot5_filename LARGEINPUT{SPOT5/Arcachon-SCENE01/IMAGERY.TIF})
set(spot5_2_filename LARGEINPUT{SPOT5/TEHERAN/IMAGERY.TIF})
set(formosat_filename LARGEINPUT{FORMOSAT/Sudouest_20071013_MS_fmsat/IMAGERY.TIF})
set(ikonos_filename LARGEINPUT{IKONOS/BLOSSEVILLE/po_2619900_blu_0000000.tif})
set(worldview2_filename LARGEINPUT{WORLDVIEW2/ROME/WV-2_standard_8band_bundle_16bit/052298844010_01_P001_MUL/09DEC10103019-M2AS-052298844010_01_P001.TIF})
set(quickbird_filename LARGEINPUT{QUICKBIRD/CEVENNES/06FEB12104912-P1BS-005533998070_01_P001.TIF})
set(Radarsat2_filename LARGEINPUT{RADARSAT2/ALTONA/Fine_Quad-Pol_Dataset/PK6621_DK406_FQ9_20080405_124900_HH_VV_HV_VH_SLC_Altona})
set(TerraSar_filename LARGEINPUT{TERRASARX/2008-03-10_GrandCanyon_SSC/TSX1_SAR__SSC______SM_S_SRA_20080310T133220_20080310T133228})
set(CosmoSkyMed_filename LARGEINPUT{COSMOSKYMED/Toulouse_spotlight/CSKS3_SCS_B_S2_08_HH_RD_SF_20110418180325_20110418180332.h5})
set(Sentinel1_filename LARGEINPUT{SENTINEL1/S1A_S6_SLC__1SSV_20150619T195043})

set(spot5_2_geom_file ${INPUTDATA}/spot5/spot5-1.geom)
set(formosat_geom_file ${INPUTDATA}/FORMOSAT_ROI_1000_100.geom)
set(pleiades_geom_file ${INPUTDATA}/pleiades/maido.geom)
set(spot6_geom_file ${INPUTDATA}/spot6/spot6-2.geom)
set(ikonos_geom_file ${INPUTDATA}/ikonos/ikonos-2.geom)
set(worldview2_geom_file ${INPUTDATA}/wv2/wv2-2.geom)
set(quickbird_geom_file ${INPUTDATA}/QB/qb-2.geom)

foreach(sensor ${sensor_list})

if (${sensor}_geom_file)
otb_add_test(NAME ioTvImageMetadataInterfaceTest_${sensor} COMMAND otbMetadataTestDriver 
  --compare-ascii 0 
  ${BASELINE_FILES}/ioTvImageMetadataInterfaceTest_${sensor}.txt
  ${TEMP}/ioTvImageMetadataInterfaceTest_${sensor}.txt
  --compare-metadata ${EPSILON_9} 
  ${${sensor}_filename}
  ${${sensor}_filename}?&geom=${${sensor}_geom_file}
  otbImageMetadataInterfaceTest
  ${${sensor}_filename}
  ${TEMP}/ioTvImageMetadataInterfaceTest_${sensor}.txt
  )
else()
otb_add_test(NAME ioTvImageMetadataInterfaceTest_${sensor} COMMAND otbMetadataTestDriver 
  --compare-ascii 0 
  ${BASELINE_FILES}/ioTvImageMetadataInterfaceTest_${sensor}.txt
  ${TEMP}/ioTvImageMetadataInterfaceTest_${sensor}.txt
  otbImageMetadataInterfaceTest
  ${${sensor}_filename}
  ${TEMP}/ioTvImageMetadataInterfaceTest_${sensor}.txt
  )
endif()

endforeach()

