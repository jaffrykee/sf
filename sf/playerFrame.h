#pragma once

#using <mscorlib.dll>
#using <System.dll>
#using <System.Data.dll>
#using <System.Xml.dll>

using namespace System::Security::Permissions;
[assembly:SecurityPermissionAttribute(SecurityAction::RequestMinimum, SkipVerification=false)];
// 
// 此源代码由 xsd 自动生成, Version=4.0.30319.33440。
// 
using namespace System;
ref class playerFrame;


/// <summary>
///Represents a strongly typed in-memory cache of data.
///</summary>
[System::Serializable, 
System::ComponentModel::DesignerCategoryAttribute(L"code"), 
System::ComponentModel::ToolboxItem(true), 
System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedDataSetSchema"), 
System::Xml::Serialization::XmlRootAttribute(L"playerFrame"), 
System::ComponentModel::Design::HelpKeywordAttribute(L"vs.data.DataSet")]
public ref class playerFrame : public ::System::Data::DataSet {
    public : ref class player_infoDataTable;
    public : ref class skin_tableDataTable;
    public : ref class skinDataTable;
    public : ref class skill_tableDataTable;
    public : ref class skillDataTable;
    public : ref class object_tableDataTable;
    public : ref class objectDataTable;
    public : ref class frame_tableDataTable;
    public : ref class frameDataTable;
    public : ref class pointDataTable;
    public : ref class box_tableDataTable;
    public : ref class boxDataTable;
    public : ref class rectDataTable;
    public : ref class player_infoRow;
    public : ref class skin_tableRow;
    public : ref class skinRow;
    public : ref class skill_tableRow;
    public : ref class skillRow;
    public : ref class object_tableRow;
    public : ref class objectRow;
    public : ref class frame_tableRow;
    public : ref class frameRow;
    public : ref class pointRow;
    public : ref class box_tableRow;
    public : ref class boxRow;
    public : ref class rectRow;
    public : ref class player_infoRowChangeEvent;
    public : ref class skin_tableRowChangeEvent;
    public : ref class skinRowChangeEvent;
    public : ref class skill_tableRowChangeEvent;
    public : ref class skillRowChangeEvent;
    public : ref class object_tableRowChangeEvent;
    public : ref class objectRowChangeEvent;
    public : ref class frame_tableRowChangeEvent;
    public : ref class frameRowChangeEvent;
    public : ref class pointRowChangeEvent;
    public : ref class box_tableRowChangeEvent;
    public : ref class boxRowChangeEvent;
    public : ref class rectRowChangeEvent;
    
    private: playerFrame::player_infoDataTable^  tableplayer_info;
    
    private: playerFrame::skin_tableDataTable^  tableskin_table;
    
    private: playerFrame::skinDataTable^  tableskin;
    
    private: playerFrame::skill_tableDataTable^  tableskill_table;
    
    private: playerFrame::skillDataTable^  tableskill;
    
    private: playerFrame::object_tableDataTable^  tableobject_table;
    
    private: playerFrame::objectDataTable^  tableobject;
    
    private: playerFrame::frame_tableDataTable^  tableframe_table;
    
    private: playerFrame::frameDataTable^  tableframe;
    
    private: playerFrame::pointDataTable^  tablepoint;
    
    private: playerFrame::box_tableDataTable^  tablebox_table;
    
    private: playerFrame::boxDataTable^  tablebox;
    
    private: playerFrame::rectDataTable^  tablerect;
    
    private: ::System::Data::DataRelation^  relationplayer_info_skin_table;
    
    private: ::System::Data::DataRelation^  relationskin_table_skin;
    
    private: ::System::Data::DataRelation^  relationplayer_info_skill_table;
    
    private: ::System::Data::DataRelation^  relationskill_table_skill;
    
    private: ::System::Data::DataRelation^  relationskill_object_table;
    
    private: ::System::Data::DataRelation^  relationobject_table_object;
    
    private: ::System::Data::DataRelation^  relationobject_frame_table;
    
    private: ::System::Data::DataRelation^  relationframe_table_frame;
    
    private: ::System::Data::DataRelation^  relationframe_point;
    
    private: ::System::Data::DataRelation^  relationframe_box_table;
    
    private: ::System::Data::DataRelation^  relationbox_table_box;
    
    private: ::System::Data::DataRelation^  relationbox_rect;
    
    private: ::System::Data::SchemaSerializationMode _schemaSerializationMode;
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void player_infoRowChangeEventHandler(::System::Object^  sender, playerFrame::player_infoRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void skin_tableRowChangeEventHandler(::System::Object^  sender, playerFrame::skin_tableRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void skinRowChangeEventHandler(::System::Object^  sender, playerFrame::skinRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void skill_tableRowChangeEventHandler(::System::Object^  sender, playerFrame::skill_tableRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void skillRowChangeEventHandler(::System::Object^  sender, playerFrame::skillRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void object_tableRowChangeEventHandler(::System::Object^  sender, playerFrame::object_tableRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void objectRowChangeEventHandler(::System::Object^  sender, playerFrame::objectRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void frame_tableRowChangeEventHandler(::System::Object^  sender, playerFrame::frame_tableRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void frameRowChangeEventHandler(::System::Object^  sender, playerFrame::frameRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void pointRowChangeEventHandler(::System::Object^  sender, playerFrame::pointRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void box_tableRowChangeEventHandler(::System::Object^  sender, playerFrame::box_tableRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void boxRowChangeEventHandler(::System::Object^  sender, playerFrame::boxRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void rectRowChangeEventHandler(::System::Object^  sender, playerFrame::rectRowChangeEvent^  e);
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    playerFrame();
    protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    playerFrame(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property playerFrame::player_infoDataTable^  player_info {
        playerFrame::player_infoDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property playerFrame::skin_tableDataTable^  skin_table {
        playerFrame::skin_tableDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property playerFrame::skinDataTable^  skin {
        playerFrame::skinDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property playerFrame::skill_tableDataTable^  skill_table {
        playerFrame::skill_tableDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property playerFrame::skillDataTable^  skill {
        playerFrame::skillDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property playerFrame::object_tableDataTable^  object_table {
        playerFrame::object_tableDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property playerFrame::objectDataTable^  object {
        playerFrame::objectDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property playerFrame::frame_tableDataTable^  frame_table {
        playerFrame::frame_tableDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property playerFrame::frameDataTable^  frame {
        playerFrame::frameDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property playerFrame::pointDataTable^  point {
        playerFrame::pointDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property playerFrame::box_tableDataTable^  box_table {
        playerFrame::box_tableDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property playerFrame::boxDataTable^  box {
        playerFrame::boxDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property playerFrame::rectDataTable^  rect {
        playerFrame::rectDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::BrowsableAttribute(true), 
    System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Visible)]
    virtual property ::System::Data::SchemaSerializationMode SchemaSerializationMode {
        ::System::Data::SchemaSerializationMode get() override;
        System::Void set(::System::Data::SchemaSerializationMode value) override;
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Hidden)]
    property ::System::Data::DataTableCollection^  Tables {
        ::System::Data::DataTableCollection^  get() new;
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Hidden)]
    property ::System::Data::DataRelationCollection^  Relations {
        ::System::Data::DataRelationCollection^  get() new;
    }
    
    protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    virtual ::System::Void InitializeDerivedDataSet() override;
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    virtual ::System::Data::DataSet^  Clone() override;
    
    protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    virtual ::System::Boolean ShouldSerializeTables() override;
    
    protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    virtual ::System::Boolean ShouldSerializeRelations() override;
    
    protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    virtual ::System::Void ReadXmlSerializable(::System::Xml::XmlReader^  reader) override;
    
    protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    virtual ::System::Xml::Schema::XmlSchema^  GetSchemaSerializable() override;
    
    internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Void InitVars();
    
    internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Void InitVars(::System::Boolean initTable);
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Void InitClass();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeplayer_info();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeskin_table();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeskin();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeskill_table();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeskill();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeobject_table();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeobject();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeframe_table();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeframe();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializepoint();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializebox_table();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializebox();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializerect();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Void SchemaChanged(::System::Object^  sender, ::System::ComponentModel::CollectionChangeEventArgs^  e);
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedDataSetSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class player_infoDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnplayer_info_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::player_infoRowChangeEventHandler^  player_infoRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::player_infoRowChangeEventHandler^  player_infoRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::player_infoRowChangeEventHandler^  player_infoRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::player_infoRowChangeEventHandler^  player_infoRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        player_infoDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        player_infoDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        player_infoDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  player_info_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::player_infoRow^  default [::System::Int32 ] {
            playerFrame::player_infoRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Addplayer_infoRow(playerFrame::player_infoRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::player_infoRow^  Addplayer_infoRow();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::player_infoRow^  Newplayer_infoRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Removeplayer_infoRow(playerFrame::player_infoRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class skin_tableDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnskin_table_Id;
        
        private: ::System::Data::DataColumn^  columnplayer_info_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skin_tableRowChangeEventHandler^  skin_tableRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skin_tableRowChangeEventHandler^  skin_tableRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skin_tableRowChangeEventHandler^  skin_tableRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skin_tableRowChangeEventHandler^  skin_tableRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skin_tableDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skin_tableDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skin_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  skin_table_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  player_info_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::skin_tableRow^  default [::System::Int32 ] {
            playerFrame::skin_tableRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Addskin_tableRow(playerFrame::skin_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::skin_tableRow^  Addskin_tableRow(playerFrame::player_infoRow^  parentplayer_infoRowByplayer_info_skin_table);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::skin_tableRow^  Newskin_tableRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Removeskin_tableRow(playerFrame::skin_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class skinDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnname;
        
        private: ::System::Data::DataColumn^  columnskin_table_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skinRowChangeEventHandler^  skinRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skinRowChangeEventHandler^  skinRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skinRowChangeEventHandler^  skinRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skinRowChangeEventHandler^  skinRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skinDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skinDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skinDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  nameColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  skin_table_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::skinRow^  default [::System::Int32 ] {
            playerFrame::skinRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddskinRow(playerFrame::skinRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::skinRow^  AddskinRow(System::String^  name, playerFrame::skin_tableRow^  parentskin_tableRowByskin_table_skin);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::skinRow^  NewskinRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void RemoveskinRow(playerFrame::skinRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class skill_tableDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnskill_table_Id;
        
        private: ::System::Data::DataColumn^  columnplayer_info_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skill_tableRowChangeEventHandler^  skill_tableRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skill_tableRowChangeEventHandler^  skill_tableRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skill_tableRowChangeEventHandler^  skill_tableRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skill_tableRowChangeEventHandler^  skill_tableRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skill_tableDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skill_tableDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skill_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  skill_table_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  player_info_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::skill_tableRow^  default [::System::Int32 ] {
            playerFrame::skill_tableRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Addskill_tableRow(playerFrame::skill_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::skill_tableRow^  Addskill_tableRow(playerFrame::player_infoRow^  parentplayer_infoRowByplayer_info_skill_table);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::skill_tableRow^  Newskill_tableRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Removeskill_tableRow(playerFrame::skill_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class skillDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columneka;
        
        private: ::System::Data::DataColumn^  columnas;
        
        private: ::System::Data::DataColumn^  columnssse;
        
        private: ::System::Data::DataColumn^  columnsavable;
        
        private: ::System::Data::DataColumn^  columnskill_Id;
        
        private: ::System::Data::DataColumn^  columnskill_table_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skillRowChangeEventHandler^  skillRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skillRowChangeEventHandler^  skillRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skillRowChangeEventHandler^  skillRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::skillRowChangeEventHandler^  skillRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  ekaColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  asColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  ssseColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  savableColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  skill_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  skill_table_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::skillRow^  default [::System::Int32 ] {
            playerFrame::skillRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddskillRow(playerFrame::skillRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::skillRow^  AddskillRow(System::String^  eka, System::String^  as, System::String^  ssse, System::Boolean savable, 
                    playerFrame::skill_tableRow^  parentskill_tableRowByskill_table_skill);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::skillRow^  NewskillRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void RemoveskillRow(playerFrame::skillRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class object_tableDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnobject_table_Id;
        
        private: ::System::Data::DataColumn^  columnskill_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::object_tableRowChangeEventHandler^  object_tableRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::object_tableRowChangeEventHandler^  object_tableRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::object_tableRowChangeEventHandler^  object_tableRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::object_tableRowChangeEventHandler^  object_tableRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        object_tableDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        object_tableDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        object_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  object_table_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  skill_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::object_tableRow^  default [::System::Int32 ] {
            playerFrame::object_tableRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Addobject_tableRow(playerFrame::object_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::object_tableRow^  Addobject_tableRow(playerFrame::skillRow^  parentskillRowByskill_object_table);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::object_tableRow^  Newobject_tableRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Removeobject_tableRow(playerFrame::object_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class objectDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnid;
        
        private: ::System::Data::DataColumn^  columnobject_Id;
        
        private: ::System::Data::DataColumn^  columnobject_table_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::objectRowChangeEventHandler^  objectRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::objectRowChangeEventHandler^  objectRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::objectRowChangeEventHandler^  objectRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::objectRowChangeEventHandler^  objectRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        objectDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        objectDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        objectDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  idColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  object_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  object_table_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::objectRow^  default [::System::Int32 ] {
            playerFrame::objectRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddobjectRow(playerFrame::objectRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::objectRow^  AddobjectRow(System::Int32 id, playerFrame::object_tableRow^  parentobject_tableRowByobject_table_object);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::objectRow^  NewobjectRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void RemoveobjectRow(playerFrame::objectRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class frame_tableDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnframe_table_Id;
        
        private: ::System::Data::DataColumn^  columnobject_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::frame_tableRowChangeEventHandler^  frame_tableRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::frame_tableRowChangeEventHandler^  frame_tableRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::frame_tableRowChangeEventHandler^  frame_tableRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::frame_tableRowChangeEventHandler^  frame_tableRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        frame_tableDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        frame_tableDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        frame_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  frame_table_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  object_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::frame_tableRow^  default [::System::Int32 ] {
            playerFrame::frame_tableRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Addframe_tableRow(playerFrame::frame_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::frame_tableRow^  Addframe_tableRow(playerFrame::objectRow^  parentobjectRowByobject_frame_table);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::frame_tableRow^  Newframe_tableRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Removeframe_tableRow(playerFrame::frame_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class frameDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnid;
        
        private: ::System::Data::DataColumn^  columnframe_Id;
        
        private: ::System::Data::DataColumn^  columnframe_table_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::frameRowChangeEventHandler^  frameRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::frameRowChangeEventHandler^  frameRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::frameRowChangeEventHandler^  frameRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::frameRowChangeEventHandler^  frameRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        frameDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        frameDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        frameDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  idColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  frame_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  frame_table_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::frameRow^  default [::System::Int32 ] {
            playerFrame::frameRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddframeRow(playerFrame::frameRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::frameRow^  AddframeRow(System::Int32 id, playerFrame::frame_tableRow^  parentframe_tableRowByframe_table_frame);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::frameRow^  NewframeRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void RemoveframeRow(playerFrame::frameRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class pointDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnx;
        
        private: ::System::Data::DataColumn^  columny;
        
        private: ::System::Data::DataColumn^  columnframe_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::pointRowChangeEventHandler^  pointRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::pointRowChangeEventHandler^  pointRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::pointRowChangeEventHandler^  pointRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::pointRowChangeEventHandler^  pointRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        pointDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        pointDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        pointDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  xColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  yColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  frame_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::pointRow^  default [::System::Int32 ] {
            playerFrame::pointRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddpointRow(playerFrame::pointRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::pointRow^  AddpointRow(System::Single x, System::Single y, playerFrame::frameRow^  parentframeRowByframe_point);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::pointRow^  NewpointRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void RemovepointRow(playerFrame::pointRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class box_tableDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnbox_table_Id;
        
        private: ::System::Data::DataColumn^  columnframe_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::box_tableRowChangeEventHandler^  box_tableRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::box_tableRowChangeEventHandler^  box_tableRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::box_tableRowChangeEventHandler^  box_tableRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::box_tableRowChangeEventHandler^  box_tableRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        box_tableDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        box_tableDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        box_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  box_table_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  frame_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::box_tableRow^  default [::System::Int32 ] {
            playerFrame::box_tableRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Addbox_tableRow(playerFrame::box_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::box_tableRow^  Addbox_tableRow(playerFrame::frameRow^  parentframeRowByframe_box_table);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::box_tableRow^  Newbox_tableRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Removebox_tableRow(playerFrame::box_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class boxDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columntype;
        
        private: ::System::Data::DataColumn^  columnbox_Id;
        
        private: ::System::Data::DataColumn^  columnbox_table_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::boxRowChangeEventHandler^  boxRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::boxRowChangeEventHandler^  boxRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::boxRowChangeEventHandler^  boxRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::boxRowChangeEventHandler^  boxRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        boxDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        boxDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        boxDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  typeColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  box_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  box_table_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::boxRow^  default [::System::Int32 ] {
            playerFrame::boxRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddboxRow(playerFrame::boxRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::boxRow^  AddboxRow(System::Int32 type, playerFrame::box_tableRow^  parentbox_tableRowBybox_table_box);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::boxRow^  NewboxRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void RemoveboxRow(playerFrame::boxRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class rectDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnt;
        
        private: ::System::Data::DataColumn^  columnl;
        
        private: ::System::Data::DataColumn^  columnb;
        
        private: ::System::Data::DataColumn^  columnr;
        
        private: ::System::Data::DataColumn^  columnbox_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::rectRowChangeEventHandler^  rectRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::rectRowChangeEventHandler^  rectRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::rectRowChangeEventHandler^  rectRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event playerFrame::rectRowChangeEventHandler^  rectRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        rectDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        rectDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        rectDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  tColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  lColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  bColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  rColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  box_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::rectRow^  default [::System::Int32 ] {
            playerFrame::rectRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddrectRow(playerFrame::rectRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::rectRow^  AddrectRow(System::Single t, System::Single l, System::Single b, System::Single r, playerFrame::boxRow^  parentboxRowBybox_rect);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        playerFrame::rectRow^  NewrectRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void RemoverectRow(playerFrame::rectRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class player_infoRow : public ::System::Data::DataRow {
        
        private: playerFrame::player_infoDataTable^  tableplayer_info;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        player_infoRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 player_info_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< playerFrame::skin_tableRow^  >^  Getskin_tableRows();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< playerFrame::skill_tableRow^  >^  Getskill_tableRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class skin_tableRow : public ::System::Data::DataRow {
        
        private: playerFrame::skin_tableDataTable^  tableskin_table;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skin_tableRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 skin_table_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 player_info_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::player_infoRow^  player_infoRow {
            playerFrame::player_infoRow^  get();
            System::Void set(playerFrame::player_infoRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isplayer_info_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setplayer_info_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< playerFrame::skinRow^  >^  GetskinRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class skinRow : public ::System::Data::DataRow {
        
        private: playerFrame::skinDataTable^  tableskin;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skinRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::String^  name {
            System::String^  get();
            System::Void set(System::String^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 skin_table_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::skin_tableRow^  skin_tableRow {
            playerFrame::skin_tableRow^  get();
            System::Void set(playerFrame::skin_tableRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isskin_table_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setskin_table_IdNull();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class skill_tableRow : public ::System::Data::DataRow {
        
        private: playerFrame::skill_tableDataTable^  tableskill_table;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skill_tableRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 skill_table_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 player_info_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::player_infoRow^  player_infoRow {
            playerFrame::player_infoRow^  get();
            System::Void set(playerFrame::player_infoRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isplayer_info_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setplayer_info_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< playerFrame::skillRow^  >^  GetskillRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class skillRow : public ::System::Data::DataRow {
        
        private: playerFrame::skillDataTable^  tableskill;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::String^  eka {
            System::String^  get();
            System::Void set(System::String^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::String^  as {
            System::String^  get();
            System::Void set(System::String^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::String^  ssse {
            System::String^  get();
            System::Void set(System::String^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Boolean savable {
            System::Boolean get();
            System::Void set(System::Boolean value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 skill_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 skill_table_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::skill_tableRow^  skill_tableRow {
            playerFrame::skill_tableRow^  get();
            System::Void set(playerFrame::skill_tableRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IsasNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SetasNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IsssseNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SetssseNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IssavableNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SetsavableNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isskill_table_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setskill_table_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< playerFrame::object_tableRow^  >^  Getobject_tableRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class object_tableRow : public ::System::Data::DataRow {
        
        private: playerFrame::object_tableDataTable^  tableobject_table;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        object_tableRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 object_table_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 skill_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::skillRow^  skillRow {
            playerFrame::skillRow^  get();
            System::Void set(playerFrame::skillRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isskill_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setskill_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< playerFrame::objectRow^  >^  GetobjectRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class objectRow : public ::System::Data::DataRow {
        
        private: playerFrame::objectDataTable^  tableobject;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        objectRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 object_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 object_table_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::object_tableRow^  object_tableRow {
            playerFrame::object_tableRow^  get();
            System::Void set(playerFrame::object_tableRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isobject_table_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setobject_table_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< playerFrame::frame_tableRow^  >^  Getframe_tableRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class frame_tableRow : public ::System::Data::DataRow {
        
        private: playerFrame::frame_tableDataTable^  tableframe_table;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        frame_tableRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 frame_table_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 object_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::objectRow^  objectRow {
            playerFrame::objectRow^  get();
            System::Void set(playerFrame::objectRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isobject_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setobject_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< playerFrame::frameRow^  >^  GetframeRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class frameRow : public ::System::Data::DataRow {
        
        private: playerFrame::frameDataTable^  tableframe;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        frameRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 frame_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 frame_table_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::frame_tableRow^  frame_tableRow {
            playerFrame::frame_tableRow^  get();
            System::Void set(playerFrame::frame_tableRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isframe_table_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setframe_table_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< playerFrame::pointRow^  >^  GetpointRows();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< playerFrame::box_tableRow^  >^  Getbox_tableRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class pointRow : public ::System::Data::DataRow {
        
        private: playerFrame::pointDataTable^  tablepoint;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        pointRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single x {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single y {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 frame_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::frameRow^  frameRow {
            playerFrame::frameRow^  get();
            System::Void set(playerFrame::frameRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IsxNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SetxNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IsyNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SetyNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isframe_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setframe_IdNull();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class box_tableRow : public ::System::Data::DataRow {
        
        private: playerFrame::box_tableDataTable^  tablebox_table;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        box_tableRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 box_table_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 frame_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::frameRow^  frameRow {
            playerFrame::frameRow^  get();
            System::Void set(playerFrame::frameRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isframe_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setframe_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< playerFrame::boxRow^  >^  GetboxRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class boxRow : public ::System::Data::DataRow {
        
        private: playerFrame::boxDataTable^  tablebox;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        boxRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 type {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 box_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 box_table_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::box_tableRow^  box_tableRow {
            playerFrame::box_tableRow^  get();
            System::Void set(playerFrame::box_tableRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IstypeNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SettypeNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isbox_table_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setbox_table_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< playerFrame::rectRow^  >^  GetrectRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class rectRow : public ::System::Data::DataRow {
        
        private: playerFrame::rectDataTable^  tablerect;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        rectRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single t {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single l {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single b {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single r {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 box_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::boxRow^  boxRow {
            playerFrame::boxRow^  get();
            System::Void set(playerFrame::boxRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IstNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SettNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IslNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SetlNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IsbNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SetbNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IsrNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SetrNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isbox_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setbox_IdNull();
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class player_infoRowChangeEvent : public ::System::EventArgs {
        
        private: playerFrame::player_infoRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        player_infoRowChangeEvent(playerFrame::player_infoRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::player_infoRow^  Row {
            playerFrame::player_infoRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class skin_tableRowChangeEvent : public ::System::EventArgs {
        
        private: playerFrame::skin_tableRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skin_tableRowChangeEvent(playerFrame::skin_tableRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::skin_tableRow^  Row {
            playerFrame::skin_tableRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class skinRowChangeEvent : public ::System::EventArgs {
        
        private: playerFrame::skinRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skinRowChangeEvent(playerFrame::skinRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::skinRow^  Row {
            playerFrame::skinRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class skill_tableRowChangeEvent : public ::System::EventArgs {
        
        private: playerFrame::skill_tableRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skill_tableRowChangeEvent(playerFrame::skill_tableRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::skill_tableRow^  Row {
            playerFrame::skill_tableRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class skillRowChangeEvent : public ::System::EventArgs {
        
        private: playerFrame::skillRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillRowChangeEvent(playerFrame::skillRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::skillRow^  Row {
            playerFrame::skillRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class object_tableRowChangeEvent : public ::System::EventArgs {
        
        private: playerFrame::object_tableRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        object_tableRowChangeEvent(playerFrame::object_tableRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::object_tableRow^  Row {
            playerFrame::object_tableRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class objectRowChangeEvent : public ::System::EventArgs {
        
        private: playerFrame::objectRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        objectRowChangeEvent(playerFrame::objectRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::objectRow^  Row {
            playerFrame::objectRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class frame_tableRowChangeEvent : public ::System::EventArgs {
        
        private: playerFrame::frame_tableRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        frame_tableRowChangeEvent(playerFrame::frame_tableRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::frame_tableRow^  Row {
            playerFrame::frame_tableRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class frameRowChangeEvent : public ::System::EventArgs {
        
        private: playerFrame::frameRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        frameRowChangeEvent(playerFrame::frameRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::frameRow^  Row {
            playerFrame::frameRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class pointRowChangeEvent : public ::System::EventArgs {
        
        private: playerFrame::pointRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        pointRowChangeEvent(playerFrame::pointRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::pointRow^  Row {
            playerFrame::pointRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class box_tableRowChangeEvent : public ::System::EventArgs {
        
        private: playerFrame::box_tableRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        box_tableRowChangeEvent(playerFrame::box_tableRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::box_tableRow^  Row {
            playerFrame::box_tableRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class boxRowChangeEvent : public ::System::EventArgs {
        
        private: playerFrame::boxRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        boxRowChangeEvent(playerFrame::boxRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::boxRow^  Row {
            playerFrame::boxRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class rectRowChangeEvent : public ::System::EventArgs {
        
        private: playerFrame::rectRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        rectRowChangeEvent(playerFrame::rectRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property playerFrame::rectRow^  Row {
            playerFrame::rectRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
};


inline playerFrame::playerFrame() {
    this->BeginInit();
    this->InitClass();
    ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &playerFrame::SchemaChanged);
    __super::Tables->CollectionChanged += schemaChangedHandler;
    __super::Relations->CollectionChanged += schemaChangedHandler;
    this->EndInit();
}

inline playerFrame::playerFrame(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataSet(info, context, false) {
    if (this->IsBinarySerialized(info, context) == true) {
        this->InitVars(false);
        ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler1 = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &playerFrame::SchemaChanged);
        this->Tables->CollectionChanged += schemaChangedHandler1;
        this->Relations->CollectionChanged += schemaChangedHandler1;
        return;
    }
    ::System::String^  strSchema = (cli::safe_cast<::System::String^  >(info->GetValue(L"XmlSchema", ::System::String::typeid)));
    if (this->DetermineSchemaSerializationMode(info, context) == ::System::Data::SchemaSerializationMode::IncludeSchema) {
        ::System::Data::DataSet^  ds = (gcnew ::System::Data::DataSet());
        ds->ReadXmlSchema((gcnew ::System::Xml::XmlTextReader((gcnew ::System::IO::StringReader(strSchema)))));
        if (ds->Tables[L"player_info"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::player_infoDataTable(ds->Tables[L"player_info"])));
        }
        if (ds->Tables[L"skin_table"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::skin_tableDataTable(ds->Tables[L"skin_table"])));
        }
        if (ds->Tables[L"skin"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::skinDataTable(ds->Tables[L"skin"])));
        }
        if (ds->Tables[L"skill_table"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::skill_tableDataTable(ds->Tables[L"skill_table"])));
        }
        if (ds->Tables[L"skill"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::skillDataTable(ds->Tables[L"skill"])));
        }
        if (ds->Tables[L"object_table"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::object_tableDataTable(ds->Tables[L"object_table"])));
        }
        if (ds->Tables[L"object"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::objectDataTable(ds->Tables[L"object"])));
        }
        if (ds->Tables[L"frame_table"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::frame_tableDataTable(ds->Tables[L"frame_table"])));
        }
        if (ds->Tables[L"frame"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::frameDataTable(ds->Tables[L"frame"])));
        }
        if (ds->Tables[L"point"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::pointDataTable(ds->Tables[L"point"])));
        }
        if (ds->Tables[L"box_table"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::box_tableDataTable(ds->Tables[L"box_table"])));
        }
        if (ds->Tables[L"box"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::boxDataTable(ds->Tables[L"box"])));
        }
        if (ds->Tables[L"rect"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::rectDataTable(ds->Tables[L"rect"])));
        }
        this->DataSetName = ds->DataSetName;
        this->Prefix = ds->Prefix;
        this->Namespace = ds->Namespace;
        this->Locale = ds->Locale;
        this->CaseSensitive = ds->CaseSensitive;
        this->EnforceConstraints = ds->EnforceConstraints;
        this->Merge(ds, false, ::System::Data::MissingSchemaAction::Add);
        this->InitVars();
    }
    else {
        this->ReadXmlSchema((gcnew ::System::Xml::XmlTextReader((gcnew ::System::IO::StringReader(strSchema)))));
    }
    this->GetSerializationData(info, context);
    ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &playerFrame::SchemaChanged);
    __super::Tables->CollectionChanged += schemaChangedHandler;
    this->Relations->CollectionChanged += schemaChangedHandler;
}

inline playerFrame::player_infoDataTable^  playerFrame::player_info::get() {
    return this->tableplayer_info;
}

inline playerFrame::skin_tableDataTable^  playerFrame::skin_table::get() {
    return this->tableskin_table;
}

inline playerFrame::skinDataTable^  playerFrame::skin::get() {
    return this->tableskin;
}

inline playerFrame::skill_tableDataTable^  playerFrame::skill_table::get() {
    return this->tableskill_table;
}

inline playerFrame::skillDataTable^  playerFrame::skill::get() {
    return this->tableskill;
}

inline playerFrame::object_tableDataTable^  playerFrame::object_table::get() {
    return this->tableobject_table;
}

inline playerFrame::objectDataTable^  playerFrame::object::get() {
    return this->tableobject;
}

inline playerFrame::frame_tableDataTable^  playerFrame::frame_table::get() {
    return this->tableframe_table;
}

inline playerFrame::frameDataTable^  playerFrame::frame::get() {
    return this->tableframe;
}

inline playerFrame::pointDataTable^  playerFrame::point::get() {
    return this->tablepoint;
}

inline playerFrame::box_tableDataTable^  playerFrame::box_table::get() {
    return this->tablebox_table;
}

inline playerFrame::boxDataTable^  playerFrame::box::get() {
    return this->tablebox;
}

inline playerFrame::rectDataTable^  playerFrame::rect::get() {
    return this->tablerect;
}

inline ::System::Data::SchemaSerializationMode playerFrame::SchemaSerializationMode::get() {
    return this->_schemaSerializationMode;
}
inline System::Void playerFrame::SchemaSerializationMode::set(::System::Data::SchemaSerializationMode value) {
    this->_schemaSerializationMode = __identifier(value);
}

inline ::System::Data::DataTableCollection^  playerFrame::Tables::get() {
    return __super::Tables;
}

inline ::System::Data::DataRelationCollection^  playerFrame::Relations::get() {
    return __super::Relations;
}

inline ::System::Void playerFrame::InitializeDerivedDataSet() {
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline ::System::Data::DataSet^  playerFrame::Clone() {
    playerFrame^  cln = (cli::safe_cast<playerFrame^  >(__super::Clone()));
    cln->InitVars();
    cln->SchemaSerializationMode = this->SchemaSerializationMode;
    return cln;
}

inline ::System::Boolean playerFrame::ShouldSerializeTables() {
    return false;
}

inline ::System::Boolean playerFrame::ShouldSerializeRelations() {
    return false;
}

inline ::System::Void playerFrame::ReadXmlSerializable(::System::Xml::XmlReader^  reader) {
    if (this->DetermineSchemaSerializationMode(reader) == ::System::Data::SchemaSerializationMode::IncludeSchema) {
        this->Reset();
        ::System::Data::DataSet^  ds = (gcnew ::System::Data::DataSet());
        ds->ReadXml(reader);
        if (ds->Tables[L"player_info"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::player_infoDataTable(ds->Tables[L"player_info"])));
        }
        if (ds->Tables[L"skin_table"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::skin_tableDataTable(ds->Tables[L"skin_table"])));
        }
        if (ds->Tables[L"skin"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::skinDataTable(ds->Tables[L"skin"])));
        }
        if (ds->Tables[L"skill_table"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::skill_tableDataTable(ds->Tables[L"skill_table"])));
        }
        if (ds->Tables[L"skill"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::skillDataTable(ds->Tables[L"skill"])));
        }
        if (ds->Tables[L"object_table"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::object_tableDataTable(ds->Tables[L"object_table"])));
        }
        if (ds->Tables[L"object"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::objectDataTable(ds->Tables[L"object"])));
        }
        if (ds->Tables[L"frame_table"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::frame_tableDataTable(ds->Tables[L"frame_table"])));
        }
        if (ds->Tables[L"frame"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::frameDataTable(ds->Tables[L"frame"])));
        }
        if (ds->Tables[L"point"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::pointDataTable(ds->Tables[L"point"])));
        }
        if (ds->Tables[L"box_table"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::box_tableDataTable(ds->Tables[L"box_table"])));
        }
        if (ds->Tables[L"box"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::boxDataTable(ds->Tables[L"box"])));
        }
        if (ds->Tables[L"rect"] != nullptr) {
            __super::Tables->Add((gcnew playerFrame::rectDataTable(ds->Tables[L"rect"])));
        }
        this->DataSetName = ds->DataSetName;
        this->Prefix = ds->Prefix;
        this->Namespace = ds->Namespace;
        this->Locale = ds->Locale;
        this->CaseSensitive = ds->CaseSensitive;
        this->EnforceConstraints = ds->EnforceConstraints;
        this->Merge(ds, false, ::System::Data::MissingSchemaAction::Add);
        this->InitVars();
    }
    else {
        this->ReadXml(reader);
        this->InitVars();
    }
}

inline ::System::Xml::Schema::XmlSchema^  playerFrame::GetSchemaSerializable() {
    ::System::IO::MemoryStream^  stream = (gcnew ::System::IO::MemoryStream());
    this->WriteXmlSchema((gcnew ::System::Xml::XmlTextWriter(stream, nullptr)));
    stream->Position = 0;
    return ::System::Xml::Schema::XmlSchema::Read((gcnew ::System::Xml::XmlTextReader(stream)), nullptr);
}

inline ::System::Void playerFrame::InitVars() {
    this->InitVars(true);
}

inline ::System::Void playerFrame::InitVars(::System::Boolean initTable) {
    this->tableplayer_info = (cli::safe_cast<playerFrame::player_infoDataTable^  >(__super::Tables[L"player_info"]));
    if (initTable == true) {
        if (this->tableplayer_info != nullptr) {
            this->tableplayer_info->InitVars();
        }
    }
    this->tableskin_table = (cli::safe_cast<playerFrame::skin_tableDataTable^  >(__super::Tables[L"skin_table"]));
    if (initTable == true) {
        if (this->tableskin_table != nullptr) {
            this->tableskin_table->InitVars();
        }
    }
    this->tableskin = (cli::safe_cast<playerFrame::skinDataTable^  >(__super::Tables[L"skin"]));
    if (initTable == true) {
        if (this->tableskin != nullptr) {
            this->tableskin->InitVars();
        }
    }
    this->tableskill_table = (cli::safe_cast<playerFrame::skill_tableDataTable^  >(__super::Tables[L"skill_table"]));
    if (initTable == true) {
        if (this->tableskill_table != nullptr) {
            this->tableskill_table->InitVars();
        }
    }
    this->tableskill = (cli::safe_cast<playerFrame::skillDataTable^  >(__super::Tables[L"skill"]));
    if (initTable == true) {
        if (this->tableskill != nullptr) {
            this->tableskill->InitVars();
        }
    }
    this->tableobject_table = (cli::safe_cast<playerFrame::object_tableDataTable^  >(__super::Tables[L"object_table"]));
    if (initTable == true) {
        if (this->tableobject_table != nullptr) {
            this->tableobject_table->InitVars();
        }
    }
    this->tableobject = (cli::safe_cast<playerFrame::objectDataTable^  >(__super::Tables[L"object"]));
    if (initTable == true) {
        if (this->tableobject != nullptr) {
            this->tableobject->InitVars();
        }
    }
    this->tableframe_table = (cli::safe_cast<playerFrame::frame_tableDataTable^  >(__super::Tables[L"frame_table"]));
    if (initTable == true) {
        if (this->tableframe_table != nullptr) {
            this->tableframe_table->InitVars();
        }
    }
    this->tableframe = (cli::safe_cast<playerFrame::frameDataTable^  >(__super::Tables[L"frame"]));
    if (initTable == true) {
        if (this->tableframe != nullptr) {
            this->tableframe->InitVars();
        }
    }
    this->tablepoint = (cli::safe_cast<playerFrame::pointDataTable^  >(__super::Tables[L"point"]));
    if (initTable == true) {
        if (this->tablepoint != nullptr) {
            this->tablepoint->InitVars();
        }
    }
    this->tablebox_table = (cli::safe_cast<playerFrame::box_tableDataTable^  >(__super::Tables[L"box_table"]));
    if (initTable == true) {
        if (this->tablebox_table != nullptr) {
            this->tablebox_table->InitVars();
        }
    }
    this->tablebox = (cli::safe_cast<playerFrame::boxDataTable^  >(__super::Tables[L"box"]));
    if (initTable == true) {
        if (this->tablebox != nullptr) {
            this->tablebox->InitVars();
        }
    }
    this->tablerect = (cli::safe_cast<playerFrame::rectDataTable^  >(__super::Tables[L"rect"]));
    if (initTable == true) {
        if (this->tablerect != nullptr) {
            this->tablerect->InitVars();
        }
    }
    this->relationplayer_info_skin_table = this->Relations[L"player_info_skin_table"];
    this->relationskin_table_skin = this->Relations[L"skin_table_skin"];
    this->relationplayer_info_skill_table = this->Relations[L"player_info_skill_table"];
    this->relationskill_table_skill = this->Relations[L"skill_table_skill"];
    this->relationskill_object_table = this->Relations[L"skill_object_table"];
    this->relationobject_table_object = this->Relations[L"object_table_object"];
    this->relationobject_frame_table = this->Relations[L"object_frame_table"];
    this->relationframe_table_frame = this->Relations[L"frame_table_frame"];
    this->relationframe_point = this->Relations[L"frame_point"];
    this->relationframe_box_table = this->Relations[L"frame_box_table"];
    this->relationbox_table_box = this->Relations[L"box_table_box"];
    this->relationbox_rect = this->Relations[L"box_rect"];
}

inline ::System::Void playerFrame::InitClass() {
    this->DataSetName = L"playerFrame";
    this->Prefix = L"";
    this->Namespace = L"http://tkmgame.com/shark/playerFrame.xsd";
    this->Locale = (gcnew ::System::Globalization::CultureInfo(L""));
    this->EnforceConstraints = true;
    this->SchemaSerializationMode = ::System::Data::SchemaSerializationMode::IncludeSchema;
    this->tableplayer_info = (gcnew playerFrame::player_infoDataTable());
    __super::Tables->Add(this->tableplayer_info);
    this->tableskin_table = (gcnew playerFrame::skin_tableDataTable());
    __super::Tables->Add(this->tableskin_table);
    this->tableskin = (gcnew playerFrame::skinDataTable());
    __super::Tables->Add(this->tableskin);
    this->tableskill_table = (gcnew playerFrame::skill_tableDataTable());
    __super::Tables->Add(this->tableskill_table);
    this->tableskill = (gcnew playerFrame::skillDataTable());
    __super::Tables->Add(this->tableskill);
    this->tableobject_table = (gcnew playerFrame::object_tableDataTable());
    __super::Tables->Add(this->tableobject_table);
    this->tableobject = (gcnew playerFrame::objectDataTable());
    __super::Tables->Add(this->tableobject);
    this->tableframe_table = (gcnew playerFrame::frame_tableDataTable());
    __super::Tables->Add(this->tableframe_table);
    this->tableframe = (gcnew playerFrame::frameDataTable());
    __super::Tables->Add(this->tableframe);
    this->tablepoint = (gcnew playerFrame::pointDataTable());
    __super::Tables->Add(this->tablepoint);
    this->tablebox_table = (gcnew playerFrame::box_tableDataTable());
    __super::Tables->Add(this->tablebox_table);
    this->tablebox = (gcnew playerFrame::boxDataTable());
    __super::Tables->Add(this->tablebox);
    this->tablerect = (gcnew playerFrame::rectDataTable());
    __super::Tables->Add(this->tablerect);
    ::System::Data::ForeignKeyConstraint^  fkc;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"player_info_skin_table", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableplayer_info->player_info_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskin_table->player_info_IdColumn}));
    this->tableskin_table->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"skin_table_skin", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskin_table->skin_table_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskin->skin_table_IdColumn}));
    this->tableskin->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"player_info_skill_table", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableplayer_info->player_info_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskill_table->player_info_IdColumn}));
    this->tableskill_table->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"skill_table_skill", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskill_table->skill_table_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskill->skill_table_IdColumn}));
    this->tableskill->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"skill_object_table", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskill->skill_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableobject_table->skill_IdColumn}));
    this->tableobject_table->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"object_table_object", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableobject_table->object_table_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableobject->object_table_IdColumn}));
    this->tableobject->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"object_frame_table", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableobject->object_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableframe_table->object_IdColumn}));
    this->tableframe_table->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"frame_table_frame", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableframe_table->frame_table_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableframe->frame_table_IdColumn}));
    this->tableframe->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"frame_point", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableframe->frame_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablepoint->frame_IdColumn}));
    this->tablepoint->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"frame_box_table", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableframe->frame_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablebox_table->frame_IdColumn}));
    this->tablebox_table->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"box_table_box", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablebox_table->box_table_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablebox->box_table_IdColumn}));
    this->tablebox->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"box_rect", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablebox->box_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablerect->box_IdColumn}));
    this->tablerect->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    this->relationplayer_info_skin_table = (gcnew ::System::Data::DataRelation(L"player_info_skin_table", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableplayer_info->player_info_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskin_table->player_info_IdColumn}, false));
    this->relationplayer_info_skin_table->Nested = true;
    this->Relations->Add(this->relationplayer_info_skin_table);
    this->relationskin_table_skin = (gcnew ::System::Data::DataRelation(L"skin_table_skin", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskin_table->skin_table_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskin->skin_table_IdColumn}, false));
    this->relationskin_table_skin->Nested = true;
    this->Relations->Add(this->relationskin_table_skin);
    this->relationplayer_info_skill_table = (gcnew ::System::Data::DataRelation(L"player_info_skill_table", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableplayer_info->player_info_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskill_table->player_info_IdColumn}, false));
    this->relationplayer_info_skill_table->Nested = true;
    this->Relations->Add(this->relationplayer_info_skill_table);
    this->relationskill_table_skill = (gcnew ::System::Data::DataRelation(L"skill_table_skill", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskill_table->skill_table_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskill->skill_table_IdColumn}, false));
    this->relationskill_table_skill->Nested = true;
    this->Relations->Add(this->relationskill_table_skill);
    this->relationskill_object_table = (gcnew ::System::Data::DataRelation(L"skill_object_table", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskill->skill_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableobject_table->skill_IdColumn}, false));
    this->relationskill_object_table->Nested = true;
    this->Relations->Add(this->relationskill_object_table);
    this->relationobject_table_object = (gcnew ::System::Data::DataRelation(L"object_table_object", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableobject_table->object_table_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableobject->object_table_IdColumn}, false));
    this->relationobject_table_object->Nested = true;
    this->Relations->Add(this->relationobject_table_object);
    this->relationobject_frame_table = (gcnew ::System::Data::DataRelation(L"object_frame_table", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableobject->object_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableframe_table->object_IdColumn}, false));
    this->relationobject_frame_table->Nested = true;
    this->Relations->Add(this->relationobject_frame_table);
    this->relationframe_table_frame = (gcnew ::System::Data::DataRelation(L"frame_table_frame", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableframe_table->frame_table_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableframe->frame_table_IdColumn}, false));
    this->relationframe_table_frame->Nested = true;
    this->Relations->Add(this->relationframe_table_frame);
    this->relationframe_point = (gcnew ::System::Data::DataRelation(L"frame_point", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableframe->frame_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablepoint->frame_IdColumn}, false));
    this->relationframe_point->Nested = true;
    this->Relations->Add(this->relationframe_point);
    this->relationframe_box_table = (gcnew ::System::Data::DataRelation(L"frame_box_table", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableframe->frame_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablebox_table->frame_IdColumn}, false));
    this->relationframe_box_table->Nested = true;
    this->Relations->Add(this->relationframe_box_table);
    this->relationbox_table_box = (gcnew ::System::Data::DataRelation(L"box_table_box", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablebox_table->box_table_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablebox->box_table_IdColumn}, false));
    this->relationbox_table_box->Nested = true;
    this->Relations->Add(this->relationbox_table_box);
    this->relationbox_rect = (gcnew ::System::Data::DataRelation(L"box_rect", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablebox->box_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablerect->box_IdColumn}, false));
    this->relationbox_rect->Nested = true;
    this->Relations->Add(this->relationbox_rect);
}

inline ::System::Boolean playerFrame::ShouldSerializeplayer_info() {
    return false;
}

inline ::System::Boolean playerFrame::ShouldSerializeskin_table() {
    return false;
}

inline ::System::Boolean playerFrame::ShouldSerializeskin() {
    return false;
}

inline ::System::Boolean playerFrame::ShouldSerializeskill_table() {
    return false;
}

inline ::System::Boolean playerFrame::ShouldSerializeskill() {
    return false;
}

inline ::System::Boolean playerFrame::ShouldSerializeobject_table() {
    return false;
}

inline ::System::Boolean playerFrame::ShouldSerializeobject() {
    return false;
}

inline ::System::Boolean playerFrame::ShouldSerializeframe_table() {
    return false;
}

inline ::System::Boolean playerFrame::ShouldSerializeframe() {
    return false;
}

inline ::System::Boolean playerFrame::ShouldSerializepoint() {
    return false;
}

inline ::System::Boolean playerFrame::ShouldSerializebox_table() {
    return false;
}

inline ::System::Boolean playerFrame::ShouldSerializebox() {
    return false;
}

inline ::System::Boolean playerFrame::ShouldSerializerect() {
    return false;
}

inline ::System::Void playerFrame::SchemaChanged(::System::Object^  sender, ::System::ComponentModel::CollectionChangeEventArgs^  e) {
    if (e->Action == ::System::ComponentModel::CollectionChangeAction::Remove) {
        this->InitVars();
    }
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  playerFrame::GetTypedDataSetSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    playerFrame^  ds = (gcnew playerFrame());
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    ::System::Xml::Schema::XmlSchemaAny^  any = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any->Namespace = ds->Namespace;
    sequence->Items->Add(any);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline playerFrame::player_infoDataTable::player_infoDataTable() {
    this->TableName = L"player_info";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline playerFrame::player_infoDataTable::player_infoDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline playerFrame::player_infoDataTable::player_infoDataTable(::System::Runtime::Serialization::SerializationInfo^  info, 
            ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  playerFrame::player_infoDataTable::player_info_IdColumn::get() {
    return this->columnplayer_info_Id;
}

inline ::System::Int32 playerFrame::player_infoDataTable::Count::get() {
    return this->Rows->Count;
}

inline playerFrame::player_infoRow^  playerFrame::player_infoDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<playerFrame::player_infoRow^  >(this->Rows[index]));
}

inline ::System::Void playerFrame::player_infoDataTable::Addplayer_infoRow(playerFrame::player_infoRow^  row) {
    this->Rows->Add(row);
}

inline playerFrame::player_infoRow^  playerFrame::player_infoDataTable::Addplayer_infoRow() {
    playerFrame::player_infoRow^  rowplayer_infoRow = (cli::safe_cast<playerFrame::player_infoRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(1) {nullptr};
    rowplayer_infoRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowplayer_infoRow);
    return rowplayer_infoRow;
}

inline ::System::Collections::IEnumerator^  playerFrame::player_infoDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  playerFrame::player_infoDataTable::Clone() {
    playerFrame::player_infoDataTable^  cln = (cli::safe_cast<playerFrame::player_infoDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  playerFrame::player_infoDataTable::CreateInstance() {
    return (gcnew playerFrame::player_infoDataTable());
}

inline ::System::Void playerFrame::player_infoDataTable::InitVars() {
    this->columnplayer_info_Id = __super::Columns[L"player_info_Id"];
}

inline ::System::Void playerFrame::player_infoDataTable::InitClass() {
    this->columnplayer_info_Id = (gcnew ::System::Data::DataColumn(L"player_info_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnplayer_info_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnplayer_info_Id}, 
            true)));
    this->columnplayer_info_Id->AutoIncrement = true;
    this->columnplayer_info_Id->AllowDBNull = false;
    this->columnplayer_info_Id->Unique = true;
}

inline playerFrame::player_infoRow^  playerFrame::player_infoDataTable::Newplayer_infoRow() {
    return (cli::safe_cast<playerFrame::player_infoRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  playerFrame::player_infoDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew playerFrame::player_infoRow(builder));
}

inline ::System::Type^  playerFrame::player_infoDataTable::GetRowType() {
    return playerFrame::player_infoRow::typeid;
}

inline ::System::Void playerFrame::player_infoDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->player_infoRowChanged(this, (gcnew playerFrame::player_infoRowChangeEvent((cli::safe_cast<playerFrame::player_infoRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::player_infoDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->player_infoRowChanging(this, (gcnew playerFrame::player_infoRowChangeEvent((cli::safe_cast<playerFrame::player_infoRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::player_infoDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->player_infoRowDeleted(this, (gcnew playerFrame::player_infoRowChangeEvent((cli::safe_cast<playerFrame::player_infoRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::player_infoDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->player_infoRowDeleting(this, (gcnew playerFrame::player_infoRowChangeEvent((cli::safe_cast<playerFrame::player_infoRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::player_infoDataTable::Removeplayer_infoRow(playerFrame::player_infoRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  playerFrame::player_infoDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    playerFrame^  ds = (gcnew playerFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"player_infoDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline playerFrame::skin_tableDataTable::skin_tableDataTable() {
    this->TableName = L"skin_table";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline playerFrame::skin_tableDataTable::skin_tableDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline playerFrame::skin_tableDataTable::skin_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, 
            ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  playerFrame::skin_tableDataTable::skin_table_IdColumn::get() {
    return this->columnskin_table_Id;
}

inline ::System::Data::DataColumn^  playerFrame::skin_tableDataTable::player_info_IdColumn::get() {
    return this->columnplayer_info_Id;
}

inline ::System::Int32 playerFrame::skin_tableDataTable::Count::get() {
    return this->Rows->Count;
}

inline playerFrame::skin_tableRow^  playerFrame::skin_tableDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<playerFrame::skin_tableRow^  >(this->Rows[index]));
}

inline ::System::Void playerFrame::skin_tableDataTable::Addskin_tableRow(playerFrame::skin_tableRow^  row) {
    this->Rows->Add(row);
}

inline playerFrame::skin_tableRow^  playerFrame::skin_tableDataTable::Addskin_tableRow(playerFrame::player_infoRow^  parentplayer_infoRowByplayer_info_skin_table) {
    playerFrame::skin_tableRow^  rowskin_tableRow = (cli::safe_cast<playerFrame::skin_tableRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {nullptr, nullptr};
    if (parentplayer_infoRowByplayer_info_skin_table != nullptr) {
        columnValuesArray[1] = parentplayer_infoRowByplayer_info_skin_table[0];
    }
    rowskin_tableRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowskin_tableRow);
    return rowskin_tableRow;
}

inline ::System::Collections::IEnumerator^  playerFrame::skin_tableDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  playerFrame::skin_tableDataTable::Clone() {
    playerFrame::skin_tableDataTable^  cln = (cli::safe_cast<playerFrame::skin_tableDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  playerFrame::skin_tableDataTable::CreateInstance() {
    return (gcnew playerFrame::skin_tableDataTable());
}

inline ::System::Void playerFrame::skin_tableDataTable::InitVars() {
    this->columnskin_table_Id = __super::Columns[L"skin_table_Id"];
    this->columnplayer_info_Id = __super::Columns[L"player_info_Id"];
}

inline ::System::Void playerFrame::skin_tableDataTable::InitClass() {
    this->columnskin_table_Id = (gcnew ::System::Data::DataColumn(L"skin_table_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnskin_table_Id);
    this->columnplayer_info_Id = (gcnew ::System::Data::DataColumn(L"player_info_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnplayer_info_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnskin_table_Id}, 
            true)));
    this->columnskin_table_Id->AutoIncrement = true;
    this->columnskin_table_Id->AllowDBNull = false;
    this->columnskin_table_Id->Unique = true;
}

inline playerFrame::skin_tableRow^  playerFrame::skin_tableDataTable::Newskin_tableRow() {
    return (cli::safe_cast<playerFrame::skin_tableRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  playerFrame::skin_tableDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew playerFrame::skin_tableRow(builder));
}

inline ::System::Type^  playerFrame::skin_tableDataTable::GetRowType() {
    return playerFrame::skin_tableRow::typeid;
}

inline ::System::Void playerFrame::skin_tableDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->skin_tableRowChanged(this, (gcnew playerFrame::skin_tableRowChangeEvent((cli::safe_cast<playerFrame::skin_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skin_tableDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->skin_tableRowChanging(this, (gcnew playerFrame::skin_tableRowChangeEvent((cli::safe_cast<playerFrame::skin_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skin_tableDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->skin_tableRowDeleted(this, (gcnew playerFrame::skin_tableRowChangeEvent((cli::safe_cast<playerFrame::skin_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skin_tableDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->skin_tableRowDeleting(this, (gcnew playerFrame::skin_tableRowChangeEvent((cli::safe_cast<playerFrame::skin_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skin_tableDataTable::Removeskin_tableRow(playerFrame::skin_tableRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  playerFrame::skin_tableDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    playerFrame^  ds = (gcnew playerFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"skin_tableDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline playerFrame::skinDataTable::skinDataTable() {
    this->TableName = L"skin";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline playerFrame::skinDataTable::skinDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline playerFrame::skinDataTable::skinDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  playerFrame::skinDataTable::nameColumn::get() {
    return this->columnname;
}

inline ::System::Data::DataColumn^  playerFrame::skinDataTable::skin_table_IdColumn::get() {
    return this->columnskin_table_Id;
}

inline ::System::Int32 playerFrame::skinDataTable::Count::get() {
    return this->Rows->Count;
}

inline playerFrame::skinRow^  playerFrame::skinDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<playerFrame::skinRow^  >(this->Rows[index]));
}

inline ::System::Void playerFrame::skinDataTable::AddskinRow(playerFrame::skinRow^  row) {
    this->Rows->Add(row);
}

inline playerFrame::skinRow^  playerFrame::skinDataTable::AddskinRow(System::String^  name, playerFrame::skin_tableRow^  parentskin_tableRowByskin_table_skin) {
    playerFrame::skinRow^  rowskinRow = (cli::safe_cast<playerFrame::skinRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {name, nullptr};
    if (parentskin_tableRowByskin_table_skin != nullptr) {
        columnValuesArray[1] = parentskin_tableRowByskin_table_skin[0];
    }
    rowskinRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowskinRow);
    return rowskinRow;
}

inline ::System::Collections::IEnumerator^  playerFrame::skinDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  playerFrame::skinDataTable::Clone() {
    playerFrame::skinDataTable^  cln = (cli::safe_cast<playerFrame::skinDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  playerFrame::skinDataTable::CreateInstance() {
    return (gcnew playerFrame::skinDataTable());
}

inline ::System::Void playerFrame::skinDataTable::InitVars() {
    this->columnname = __super::Columns[L"name"];
    this->columnskin_table_Id = __super::Columns[L"skin_table_Id"];
}

inline ::System::Void playerFrame::skinDataTable::InitClass() {
    this->columnname = (gcnew ::System::Data::DataColumn(L"name", ::System::String::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columnname);
    this->columnskin_table_Id = (gcnew ::System::Data::DataColumn(L"skin_table_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnskin_table_Id);
    this->columnname->AllowDBNull = false;
    this->columnname->Namespace = L"";
}

inline playerFrame::skinRow^  playerFrame::skinDataTable::NewskinRow() {
    return (cli::safe_cast<playerFrame::skinRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  playerFrame::skinDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew playerFrame::skinRow(builder));
}

inline ::System::Type^  playerFrame::skinDataTable::GetRowType() {
    return playerFrame::skinRow::typeid;
}

inline ::System::Void playerFrame::skinDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->skinRowChanged(this, (gcnew playerFrame::skinRowChangeEvent((cli::safe_cast<playerFrame::skinRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skinDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->skinRowChanging(this, (gcnew playerFrame::skinRowChangeEvent((cli::safe_cast<playerFrame::skinRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skinDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->skinRowDeleted(this, (gcnew playerFrame::skinRowChangeEvent((cli::safe_cast<playerFrame::skinRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skinDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->skinRowDeleting(this, (gcnew playerFrame::skinRowChangeEvent((cli::safe_cast<playerFrame::skinRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skinDataTable::RemoveskinRow(playerFrame::skinRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  playerFrame::skinDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    playerFrame^  ds = (gcnew playerFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"skinDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline playerFrame::skill_tableDataTable::skill_tableDataTable() {
    this->TableName = L"skill_table";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline playerFrame::skill_tableDataTable::skill_tableDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline playerFrame::skill_tableDataTable::skill_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, 
            ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  playerFrame::skill_tableDataTable::skill_table_IdColumn::get() {
    return this->columnskill_table_Id;
}

inline ::System::Data::DataColumn^  playerFrame::skill_tableDataTable::player_info_IdColumn::get() {
    return this->columnplayer_info_Id;
}

inline ::System::Int32 playerFrame::skill_tableDataTable::Count::get() {
    return this->Rows->Count;
}

inline playerFrame::skill_tableRow^  playerFrame::skill_tableDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<playerFrame::skill_tableRow^  >(this->Rows[index]));
}

inline ::System::Void playerFrame::skill_tableDataTable::Addskill_tableRow(playerFrame::skill_tableRow^  row) {
    this->Rows->Add(row);
}

inline playerFrame::skill_tableRow^  playerFrame::skill_tableDataTable::Addskill_tableRow(playerFrame::player_infoRow^  parentplayer_infoRowByplayer_info_skill_table) {
    playerFrame::skill_tableRow^  rowskill_tableRow = (cli::safe_cast<playerFrame::skill_tableRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {nullptr, nullptr};
    if (parentplayer_infoRowByplayer_info_skill_table != nullptr) {
        columnValuesArray[1] = parentplayer_infoRowByplayer_info_skill_table[0];
    }
    rowskill_tableRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowskill_tableRow);
    return rowskill_tableRow;
}

inline ::System::Collections::IEnumerator^  playerFrame::skill_tableDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  playerFrame::skill_tableDataTable::Clone() {
    playerFrame::skill_tableDataTable^  cln = (cli::safe_cast<playerFrame::skill_tableDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  playerFrame::skill_tableDataTable::CreateInstance() {
    return (gcnew playerFrame::skill_tableDataTable());
}

inline ::System::Void playerFrame::skill_tableDataTable::InitVars() {
    this->columnskill_table_Id = __super::Columns[L"skill_table_Id"];
    this->columnplayer_info_Id = __super::Columns[L"player_info_Id"];
}

inline ::System::Void playerFrame::skill_tableDataTable::InitClass() {
    this->columnskill_table_Id = (gcnew ::System::Data::DataColumn(L"skill_table_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnskill_table_Id);
    this->columnplayer_info_Id = (gcnew ::System::Data::DataColumn(L"player_info_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnplayer_info_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnskill_table_Id}, 
            true)));
    this->columnskill_table_Id->AutoIncrement = true;
    this->columnskill_table_Id->AllowDBNull = false;
    this->columnskill_table_Id->Unique = true;
}

inline playerFrame::skill_tableRow^  playerFrame::skill_tableDataTable::Newskill_tableRow() {
    return (cli::safe_cast<playerFrame::skill_tableRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  playerFrame::skill_tableDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew playerFrame::skill_tableRow(builder));
}

inline ::System::Type^  playerFrame::skill_tableDataTable::GetRowType() {
    return playerFrame::skill_tableRow::typeid;
}

inline ::System::Void playerFrame::skill_tableDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->skill_tableRowChanged(this, (gcnew playerFrame::skill_tableRowChangeEvent((cli::safe_cast<playerFrame::skill_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skill_tableDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->skill_tableRowChanging(this, (gcnew playerFrame::skill_tableRowChangeEvent((cli::safe_cast<playerFrame::skill_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skill_tableDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->skill_tableRowDeleted(this, (gcnew playerFrame::skill_tableRowChangeEvent((cli::safe_cast<playerFrame::skill_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skill_tableDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->skill_tableRowDeleting(this, (gcnew playerFrame::skill_tableRowChangeEvent((cli::safe_cast<playerFrame::skill_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skill_tableDataTable::Removeskill_tableRow(playerFrame::skill_tableRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  playerFrame::skill_tableDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    playerFrame^  ds = (gcnew playerFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"skill_tableDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline playerFrame::skillDataTable::skillDataTable() {
    this->TableName = L"skill";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline playerFrame::skillDataTable::skillDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline playerFrame::skillDataTable::skillDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  playerFrame::skillDataTable::ekaColumn::get() {
    return this->columneka;
}

inline ::System::Data::DataColumn^  playerFrame::skillDataTable::asColumn::get() {
    return this->columnas;
}

inline ::System::Data::DataColumn^  playerFrame::skillDataTable::ssseColumn::get() {
    return this->columnssse;
}

inline ::System::Data::DataColumn^  playerFrame::skillDataTable::savableColumn::get() {
    return this->columnsavable;
}

inline ::System::Data::DataColumn^  playerFrame::skillDataTable::skill_IdColumn::get() {
    return this->columnskill_Id;
}

inline ::System::Data::DataColumn^  playerFrame::skillDataTable::skill_table_IdColumn::get() {
    return this->columnskill_table_Id;
}

inline ::System::Int32 playerFrame::skillDataTable::Count::get() {
    return this->Rows->Count;
}

inline playerFrame::skillRow^  playerFrame::skillDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<playerFrame::skillRow^  >(this->Rows[index]));
}

inline ::System::Void playerFrame::skillDataTable::AddskillRow(playerFrame::skillRow^  row) {
    this->Rows->Add(row);
}

inline playerFrame::skillRow^  playerFrame::skillDataTable::AddskillRow(System::String^  eka, System::String^  as, System::String^  ssse, 
            System::Boolean savable, playerFrame::skill_tableRow^  parentskill_tableRowByskill_table_skill) {
    playerFrame::skillRow^  rowskillRow = (cli::safe_cast<playerFrame::skillRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(6) {eka, as, ssse, savable, 
        nullptr, nullptr};
    if (parentskill_tableRowByskill_table_skill != nullptr) {
        columnValuesArray[5] = parentskill_tableRowByskill_table_skill[0];
    }
    rowskillRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowskillRow);
    return rowskillRow;
}

inline ::System::Collections::IEnumerator^  playerFrame::skillDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  playerFrame::skillDataTable::Clone() {
    playerFrame::skillDataTable^  cln = (cli::safe_cast<playerFrame::skillDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  playerFrame::skillDataTable::CreateInstance() {
    return (gcnew playerFrame::skillDataTable());
}

inline ::System::Void playerFrame::skillDataTable::InitVars() {
    this->columneka = __super::Columns[L"eka"];
    this->columnas = __super::Columns[L"as"];
    this->columnssse = __super::Columns[L"ssse"];
    this->columnsavable = __super::Columns[L"savable"];
    this->columnskill_Id = __super::Columns[L"skill_Id"];
    this->columnskill_table_Id = __super::Columns[L"skill_table_Id"];
}

inline ::System::Void playerFrame::skillDataTable::InitClass() {
    this->columneka = (gcnew ::System::Data::DataColumn(L"eka", ::System::String::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columneka);
    this->columnas = (gcnew ::System::Data::DataColumn(L"as", ::System::String::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columnas);
    this->columnssse = (gcnew ::System::Data::DataColumn(L"ssse", ::System::String::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columnssse);
    this->columnsavable = (gcnew ::System::Data::DataColumn(L"savable", ::System::Boolean::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columnsavable);
    this->columnskill_Id = (gcnew ::System::Data::DataColumn(L"skill_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnskill_Id);
    this->columnskill_table_Id = (gcnew ::System::Data::DataColumn(L"skill_table_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnskill_table_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnskill_Id}, 
            true)));
    this->columneka->AllowDBNull = false;
    this->columneka->Namespace = L"";
    this->columnas->Namespace = L"";
    this->columnas->DefaultValue = (cli::safe_cast<System::String^  >(L"def"));
    this->columnssse->Namespace = L"";
    this->columnssse->DefaultValue = (cli::safe_cast<System::String^  >(L"basic"));
    this->columnsavable->Namespace = L"";
    this->columnsavable->DefaultValue = static_cast<System::Boolean>(false);
    this->columnskill_Id->AutoIncrement = true;
    this->columnskill_Id->AllowDBNull = false;
    this->columnskill_Id->Unique = true;
}

inline playerFrame::skillRow^  playerFrame::skillDataTable::NewskillRow() {
    return (cli::safe_cast<playerFrame::skillRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  playerFrame::skillDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew playerFrame::skillRow(builder));
}

inline ::System::Type^  playerFrame::skillDataTable::GetRowType() {
    return playerFrame::skillRow::typeid;
}

inline ::System::Void playerFrame::skillDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->skillRowChanged(this, (gcnew playerFrame::skillRowChangeEvent((cli::safe_cast<playerFrame::skillRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skillDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->skillRowChanging(this, (gcnew playerFrame::skillRowChangeEvent((cli::safe_cast<playerFrame::skillRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skillDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->skillRowDeleted(this, (gcnew playerFrame::skillRowChangeEvent((cli::safe_cast<playerFrame::skillRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skillDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->skillRowDeleting(this, (gcnew playerFrame::skillRowChangeEvent((cli::safe_cast<playerFrame::skillRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::skillDataTable::RemoveskillRow(playerFrame::skillRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  playerFrame::skillDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    playerFrame^  ds = (gcnew playerFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"skillDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline playerFrame::object_tableDataTable::object_tableDataTable() {
    this->TableName = L"object_table";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline playerFrame::object_tableDataTable::object_tableDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline playerFrame::object_tableDataTable::object_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, 
            ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  playerFrame::object_tableDataTable::object_table_IdColumn::get() {
    return this->columnobject_table_Id;
}

inline ::System::Data::DataColumn^  playerFrame::object_tableDataTable::skill_IdColumn::get() {
    return this->columnskill_Id;
}

inline ::System::Int32 playerFrame::object_tableDataTable::Count::get() {
    return this->Rows->Count;
}

inline playerFrame::object_tableRow^  playerFrame::object_tableDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<playerFrame::object_tableRow^  >(this->Rows[index]));
}

inline ::System::Void playerFrame::object_tableDataTable::Addobject_tableRow(playerFrame::object_tableRow^  row) {
    this->Rows->Add(row);
}

inline playerFrame::object_tableRow^  playerFrame::object_tableDataTable::Addobject_tableRow(playerFrame::skillRow^  parentskillRowByskill_object_table) {
    playerFrame::object_tableRow^  rowobject_tableRow = (cli::safe_cast<playerFrame::object_tableRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {nullptr, nullptr};
    if (parentskillRowByskill_object_table != nullptr) {
        columnValuesArray[1] = parentskillRowByskill_object_table[4];
    }
    rowobject_tableRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowobject_tableRow);
    return rowobject_tableRow;
}

inline ::System::Collections::IEnumerator^  playerFrame::object_tableDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  playerFrame::object_tableDataTable::Clone() {
    playerFrame::object_tableDataTable^  cln = (cli::safe_cast<playerFrame::object_tableDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  playerFrame::object_tableDataTable::CreateInstance() {
    return (gcnew playerFrame::object_tableDataTable());
}

inline ::System::Void playerFrame::object_tableDataTable::InitVars() {
    this->columnobject_table_Id = __super::Columns[L"object_table_Id"];
    this->columnskill_Id = __super::Columns[L"skill_Id"];
}

inline ::System::Void playerFrame::object_tableDataTable::InitClass() {
    this->columnobject_table_Id = (gcnew ::System::Data::DataColumn(L"object_table_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnobject_table_Id);
    this->columnskill_Id = (gcnew ::System::Data::DataColumn(L"skill_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnskill_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnobject_table_Id}, 
            true)));
    this->columnobject_table_Id->AutoIncrement = true;
    this->columnobject_table_Id->AllowDBNull = false;
    this->columnobject_table_Id->Unique = true;
}

inline playerFrame::object_tableRow^  playerFrame::object_tableDataTable::Newobject_tableRow() {
    return (cli::safe_cast<playerFrame::object_tableRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  playerFrame::object_tableDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew playerFrame::object_tableRow(builder));
}

inline ::System::Type^  playerFrame::object_tableDataTable::GetRowType() {
    return playerFrame::object_tableRow::typeid;
}

inline ::System::Void playerFrame::object_tableDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->object_tableRowChanged(this, (gcnew playerFrame::object_tableRowChangeEvent((cli::safe_cast<playerFrame::object_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::object_tableDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->object_tableRowChanging(this, (gcnew playerFrame::object_tableRowChangeEvent((cli::safe_cast<playerFrame::object_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::object_tableDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->object_tableRowDeleted(this, (gcnew playerFrame::object_tableRowChangeEvent((cli::safe_cast<playerFrame::object_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::object_tableDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->object_tableRowDeleting(this, (gcnew playerFrame::object_tableRowChangeEvent((cli::safe_cast<playerFrame::object_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::object_tableDataTable::Removeobject_tableRow(playerFrame::object_tableRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  playerFrame::object_tableDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    playerFrame^  ds = (gcnew playerFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"object_tableDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline playerFrame::objectDataTable::objectDataTable() {
    this->TableName = L"object";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline playerFrame::objectDataTable::objectDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline playerFrame::objectDataTable::objectDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  playerFrame::objectDataTable::idColumn::get() {
    return this->columnid;
}

inline ::System::Data::DataColumn^  playerFrame::objectDataTable::object_IdColumn::get() {
    return this->columnobject_Id;
}

inline ::System::Data::DataColumn^  playerFrame::objectDataTable::object_table_IdColumn::get() {
    return this->columnobject_table_Id;
}

inline ::System::Int32 playerFrame::objectDataTable::Count::get() {
    return this->Rows->Count;
}

inline playerFrame::objectRow^  playerFrame::objectDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<playerFrame::objectRow^  >(this->Rows[index]));
}

inline ::System::Void playerFrame::objectDataTable::AddobjectRow(playerFrame::objectRow^  row) {
    this->Rows->Add(row);
}

inline playerFrame::objectRow^  playerFrame::objectDataTable::AddobjectRow(System::Int32 id, playerFrame::object_tableRow^  parentobject_tableRowByobject_table_object) {
    playerFrame::objectRow^  rowobjectRow = (cli::safe_cast<playerFrame::objectRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(3) {id, nullptr, nullptr};
    if (parentobject_tableRowByobject_table_object != nullptr) {
        columnValuesArray[2] = parentobject_tableRowByobject_table_object[0];
    }
    rowobjectRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowobjectRow);
    return rowobjectRow;
}

inline ::System::Collections::IEnumerator^  playerFrame::objectDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  playerFrame::objectDataTable::Clone() {
    playerFrame::objectDataTable^  cln = (cli::safe_cast<playerFrame::objectDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  playerFrame::objectDataTable::CreateInstance() {
    return (gcnew playerFrame::objectDataTable());
}

inline ::System::Void playerFrame::objectDataTable::InitVars() {
    this->columnid = __super::Columns[L"id"];
    this->columnobject_Id = __super::Columns[L"object_Id"];
    this->columnobject_table_Id = __super::Columns[L"object_table_Id"];
}

inline ::System::Void playerFrame::objectDataTable::InitClass() {
    this->columnid = (gcnew ::System::Data::DataColumn(L"id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columnid);
    this->columnobject_Id = (gcnew ::System::Data::DataColumn(L"object_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnobject_Id);
    this->columnobject_table_Id = (gcnew ::System::Data::DataColumn(L"object_table_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnobject_table_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnobject_Id}, 
            true)));
    this->columnid->AllowDBNull = false;
    this->columnid->Namespace = L"";
    this->columnobject_Id->AutoIncrement = true;
    this->columnobject_Id->AllowDBNull = false;
    this->columnobject_Id->Unique = true;
}

inline playerFrame::objectRow^  playerFrame::objectDataTable::NewobjectRow() {
    return (cli::safe_cast<playerFrame::objectRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  playerFrame::objectDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew playerFrame::objectRow(builder));
}

inline ::System::Type^  playerFrame::objectDataTable::GetRowType() {
    return playerFrame::objectRow::typeid;
}

inline ::System::Void playerFrame::objectDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->objectRowChanged(this, (gcnew playerFrame::objectRowChangeEvent((cli::safe_cast<playerFrame::objectRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::objectDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->objectRowChanging(this, (gcnew playerFrame::objectRowChangeEvent((cli::safe_cast<playerFrame::objectRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::objectDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->objectRowDeleted(this, (gcnew playerFrame::objectRowChangeEvent((cli::safe_cast<playerFrame::objectRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::objectDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->objectRowDeleting(this, (gcnew playerFrame::objectRowChangeEvent((cli::safe_cast<playerFrame::objectRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::objectDataTable::RemoveobjectRow(playerFrame::objectRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  playerFrame::objectDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    playerFrame^  ds = (gcnew playerFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"objectDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline playerFrame::frame_tableDataTable::frame_tableDataTable() {
    this->TableName = L"frame_table";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline playerFrame::frame_tableDataTable::frame_tableDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline playerFrame::frame_tableDataTable::frame_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, 
            ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  playerFrame::frame_tableDataTable::frame_table_IdColumn::get() {
    return this->columnframe_table_Id;
}

inline ::System::Data::DataColumn^  playerFrame::frame_tableDataTable::object_IdColumn::get() {
    return this->columnobject_Id;
}

inline ::System::Int32 playerFrame::frame_tableDataTable::Count::get() {
    return this->Rows->Count;
}

inline playerFrame::frame_tableRow^  playerFrame::frame_tableDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<playerFrame::frame_tableRow^  >(this->Rows[index]));
}

inline ::System::Void playerFrame::frame_tableDataTable::Addframe_tableRow(playerFrame::frame_tableRow^  row) {
    this->Rows->Add(row);
}

inline playerFrame::frame_tableRow^  playerFrame::frame_tableDataTable::Addframe_tableRow(playerFrame::objectRow^  parentobjectRowByobject_frame_table) {
    playerFrame::frame_tableRow^  rowframe_tableRow = (cli::safe_cast<playerFrame::frame_tableRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {nullptr, nullptr};
    if (parentobjectRowByobject_frame_table != nullptr) {
        columnValuesArray[1] = parentobjectRowByobject_frame_table[1];
    }
    rowframe_tableRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowframe_tableRow);
    return rowframe_tableRow;
}

inline ::System::Collections::IEnumerator^  playerFrame::frame_tableDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  playerFrame::frame_tableDataTable::Clone() {
    playerFrame::frame_tableDataTable^  cln = (cli::safe_cast<playerFrame::frame_tableDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  playerFrame::frame_tableDataTable::CreateInstance() {
    return (gcnew playerFrame::frame_tableDataTable());
}

inline ::System::Void playerFrame::frame_tableDataTable::InitVars() {
    this->columnframe_table_Id = __super::Columns[L"frame_table_Id"];
    this->columnobject_Id = __super::Columns[L"object_Id"];
}

inline ::System::Void playerFrame::frame_tableDataTable::InitClass() {
    this->columnframe_table_Id = (gcnew ::System::Data::DataColumn(L"frame_table_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnframe_table_Id);
    this->columnobject_Id = (gcnew ::System::Data::DataColumn(L"object_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnobject_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnframe_table_Id}, 
            true)));
    this->columnframe_table_Id->AutoIncrement = true;
    this->columnframe_table_Id->AllowDBNull = false;
    this->columnframe_table_Id->Unique = true;
}

inline playerFrame::frame_tableRow^  playerFrame::frame_tableDataTable::Newframe_tableRow() {
    return (cli::safe_cast<playerFrame::frame_tableRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  playerFrame::frame_tableDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew playerFrame::frame_tableRow(builder));
}

inline ::System::Type^  playerFrame::frame_tableDataTable::GetRowType() {
    return playerFrame::frame_tableRow::typeid;
}

inline ::System::Void playerFrame::frame_tableDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->frame_tableRowChanged(this, (gcnew playerFrame::frame_tableRowChangeEvent((cli::safe_cast<playerFrame::frame_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::frame_tableDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->frame_tableRowChanging(this, (gcnew playerFrame::frame_tableRowChangeEvent((cli::safe_cast<playerFrame::frame_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::frame_tableDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->frame_tableRowDeleted(this, (gcnew playerFrame::frame_tableRowChangeEvent((cli::safe_cast<playerFrame::frame_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::frame_tableDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->frame_tableRowDeleting(this, (gcnew playerFrame::frame_tableRowChangeEvent((cli::safe_cast<playerFrame::frame_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::frame_tableDataTable::Removeframe_tableRow(playerFrame::frame_tableRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  playerFrame::frame_tableDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    playerFrame^  ds = (gcnew playerFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"frame_tableDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline playerFrame::frameDataTable::frameDataTable() {
    this->TableName = L"frame";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline playerFrame::frameDataTable::frameDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline playerFrame::frameDataTable::frameDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  playerFrame::frameDataTable::idColumn::get() {
    return this->columnid;
}

inline ::System::Data::DataColumn^  playerFrame::frameDataTable::frame_IdColumn::get() {
    return this->columnframe_Id;
}

inline ::System::Data::DataColumn^  playerFrame::frameDataTable::frame_table_IdColumn::get() {
    return this->columnframe_table_Id;
}

inline ::System::Int32 playerFrame::frameDataTable::Count::get() {
    return this->Rows->Count;
}

inline playerFrame::frameRow^  playerFrame::frameDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<playerFrame::frameRow^  >(this->Rows[index]));
}

inline ::System::Void playerFrame::frameDataTable::AddframeRow(playerFrame::frameRow^  row) {
    this->Rows->Add(row);
}

inline playerFrame::frameRow^  playerFrame::frameDataTable::AddframeRow(System::Int32 id, playerFrame::frame_tableRow^  parentframe_tableRowByframe_table_frame) {
    playerFrame::frameRow^  rowframeRow = (cli::safe_cast<playerFrame::frameRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(3) {id, nullptr, nullptr};
    if (parentframe_tableRowByframe_table_frame != nullptr) {
        columnValuesArray[2] = parentframe_tableRowByframe_table_frame[0];
    }
    rowframeRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowframeRow);
    return rowframeRow;
}

inline ::System::Collections::IEnumerator^  playerFrame::frameDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  playerFrame::frameDataTable::Clone() {
    playerFrame::frameDataTable^  cln = (cli::safe_cast<playerFrame::frameDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  playerFrame::frameDataTable::CreateInstance() {
    return (gcnew playerFrame::frameDataTable());
}

inline ::System::Void playerFrame::frameDataTable::InitVars() {
    this->columnid = __super::Columns[L"id"];
    this->columnframe_Id = __super::Columns[L"frame_Id"];
    this->columnframe_table_Id = __super::Columns[L"frame_table_Id"];
}

inline ::System::Void playerFrame::frameDataTable::InitClass() {
    this->columnid = (gcnew ::System::Data::DataColumn(L"id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columnid);
    this->columnframe_Id = (gcnew ::System::Data::DataColumn(L"frame_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnframe_Id);
    this->columnframe_table_Id = (gcnew ::System::Data::DataColumn(L"frame_table_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnframe_table_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnframe_Id}, 
            true)));
    this->columnid->AllowDBNull = false;
    this->columnid->Namespace = L"";
    this->columnframe_Id->AutoIncrement = true;
    this->columnframe_Id->AllowDBNull = false;
    this->columnframe_Id->Unique = true;
}

inline playerFrame::frameRow^  playerFrame::frameDataTable::NewframeRow() {
    return (cli::safe_cast<playerFrame::frameRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  playerFrame::frameDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew playerFrame::frameRow(builder));
}

inline ::System::Type^  playerFrame::frameDataTable::GetRowType() {
    return playerFrame::frameRow::typeid;
}

inline ::System::Void playerFrame::frameDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->frameRowChanged(this, (gcnew playerFrame::frameRowChangeEvent((cli::safe_cast<playerFrame::frameRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::frameDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->frameRowChanging(this, (gcnew playerFrame::frameRowChangeEvent((cli::safe_cast<playerFrame::frameRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::frameDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->frameRowDeleted(this, (gcnew playerFrame::frameRowChangeEvent((cli::safe_cast<playerFrame::frameRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::frameDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->frameRowDeleting(this, (gcnew playerFrame::frameRowChangeEvent((cli::safe_cast<playerFrame::frameRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::frameDataTable::RemoveframeRow(playerFrame::frameRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  playerFrame::frameDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    playerFrame^  ds = (gcnew playerFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"frameDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline playerFrame::pointDataTable::pointDataTable() {
    this->TableName = L"point";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline playerFrame::pointDataTable::pointDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline playerFrame::pointDataTable::pointDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  playerFrame::pointDataTable::xColumn::get() {
    return this->columnx;
}

inline ::System::Data::DataColumn^  playerFrame::pointDataTable::yColumn::get() {
    return this->columny;
}

inline ::System::Data::DataColumn^  playerFrame::pointDataTable::frame_IdColumn::get() {
    return this->columnframe_Id;
}

inline ::System::Int32 playerFrame::pointDataTable::Count::get() {
    return this->Rows->Count;
}

inline playerFrame::pointRow^  playerFrame::pointDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<playerFrame::pointRow^  >(this->Rows[index]));
}

inline ::System::Void playerFrame::pointDataTable::AddpointRow(playerFrame::pointRow^  row) {
    this->Rows->Add(row);
}

inline playerFrame::pointRow^  playerFrame::pointDataTable::AddpointRow(System::Single x, System::Single y, playerFrame::frameRow^  parentframeRowByframe_point) {
    playerFrame::pointRow^  rowpointRow = (cli::safe_cast<playerFrame::pointRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(3) {x, y, nullptr};
    if (parentframeRowByframe_point != nullptr) {
        columnValuesArray[2] = parentframeRowByframe_point[1];
    }
    rowpointRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowpointRow);
    return rowpointRow;
}

inline ::System::Collections::IEnumerator^  playerFrame::pointDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  playerFrame::pointDataTable::Clone() {
    playerFrame::pointDataTable^  cln = (cli::safe_cast<playerFrame::pointDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  playerFrame::pointDataTable::CreateInstance() {
    return (gcnew playerFrame::pointDataTable());
}

inline ::System::Void playerFrame::pointDataTable::InitVars() {
    this->columnx = __super::Columns[L"x"];
    this->columny = __super::Columns[L"y"];
    this->columnframe_Id = __super::Columns[L"frame_Id"];
}

inline ::System::Void playerFrame::pointDataTable::InitClass() {
    this->columnx = (gcnew ::System::Data::DataColumn(L"x", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columnx);
    this->columny = (gcnew ::System::Data::DataColumn(L"y", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columny);
    this->columnframe_Id = (gcnew ::System::Data::DataColumn(L"frame_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnframe_Id);
    this->columnx->Namespace = L"";
    this->columny->Namespace = L"";
}

inline playerFrame::pointRow^  playerFrame::pointDataTable::NewpointRow() {
    return (cli::safe_cast<playerFrame::pointRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  playerFrame::pointDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew playerFrame::pointRow(builder));
}

inline ::System::Type^  playerFrame::pointDataTable::GetRowType() {
    return playerFrame::pointRow::typeid;
}

inline ::System::Void playerFrame::pointDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->pointRowChanged(this, (gcnew playerFrame::pointRowChangeEvent((cli::safe_cast<playerFrame::pointRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::pointDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->pointRowChanging(this, (gcnew playerFrame::pointRowChangeEvent((cli::safe_cast<playerFrame::pointRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::pointDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->pointRowDeleted(this, (gcnew playerFrame::pointRowChangeEvent((cli::safe_cast<playerFrame::pointRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::pointDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->pointRowDeleting(this, (gcnew playerFrame::pointRowChangeEvent((cli::safe_cast<playerFrame::pointRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::pointDataTable::RemovepointRow(playerFrame::pointRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  playerFrame::pointDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    playerFrame^  ds = (gcnew playerFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"pointDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline playerFrame::box_tableDataTable::box_tableDataTable() {
    this->TableName = L"box_table";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline playerFrame::box_tableDataTable::box_tableDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline playerFrame::box_tableDataTable::box_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  playerFrame::box_tableDataTable::box_table_IdColumn::get() {
    return this->columnbox_table_Id;
}

inline ::System::Data::DataColumn^  playerFrame::box_tableDataTable::frame_IdColumn::get() {
    return this->columnframe_Id;
}

inline ::System::Int32 playerFrame::box_tableDataTable::Count::get() {
    return this->Rows->Count;
}

inline playerFrame::box_tableRow^  playerFrame::box_tableDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<playerFrame::box_tableRow^  >(this->Rows[index]));
}

inline ::System::Void playerFrame::box_tableDataTable::Addbox_tableRow(playerFrame::box_tableRow^  row) {
    this->Rows->Add(row);
}

inline playerFrame::box_tableRow^  playerFrame::box_tableDataTable::Addbox_tableRow(playerFrame::frameRow^  parentframeRowByframe_box_table) {
    playerFrame::box_tableRow^  rowbox_tableRow = (cli::safe_cast<playerFrame::box_tableRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {nullptr, nullptr};
    if (parentframeRowByframe_box_table != nullptr) {
        columnValuesArray[1] = parentframeRowByframe_box_table[1];
    }
    rowbox_tableRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowbox_tableRow);
    return rowbox_tableRow;
}

inline ::System::Collections::IEnumerator^  playerFrame::box_tableDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  playerFrame::box_tableDataTable::Clone() {
    playerFrame::box_tableDataTable^  cln = (cli::safe_cast<playerFrame::box_tableDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  playerFrame::box_tableDataTable::CreateInstance() {
    return (gcnew playerFrame::box_tableDataTable());
}

inline ::System::Void playerFrame::box_tableDataTable::InitVars() {
    this->columnbox_table_Id = __super::Columns[L"box_table_Id"];
    this->columnframe_Id = __super::Columns[L"frame_Id"];
}

inline ::System::Void playerFrame::box_tableDataTable::InitClass() {
    this->columnbox_table_Id = (gcnew ::System::Data::DataColumn(L"box_table_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnbox_table_Id);
    this->columnframe_Id = (gcnew ::System::Data::DataColumn(L"frame_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnframe_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnbox_table_Id}, 
            true)));
    this->columnbox_table_Id->AutoIncrement = true;
    this->columnbox_table_Id->AllowDBNull = false;
    this->columnbox_table_Id->Unique = true;
}

inline playerFrame::box_tableRow^  playerFrame::box_tableDataTable::Newbox_tableRow() {
    return (cli::safe_cast<playerFrame::box_tableRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  playerFrame::box_tableDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew playerFrame::box_tableRow(builder));
}

inline ::System::Type^  playerFrame::box_tableDataTable::GetRowType() {
    return playerFrame::box_tableRow::typeid;
}

inline ::System::Void playerFrame::box_tableDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->box_tableRowChanged(this, (gcnew playerFrame::box_tableRowChangeEvent((cli::safe_cast<playerFrame::box_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::box_tableDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->box_tableRowChanging(this, (gcnew playerFrame::box_tableRowChangeEvent((cli::safe_cast<playerFrame::box_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::box_tableDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->box_tableRowDeleted(this, (gcnew playerFrame::box_tableRowChangeEvent((cli::safe_cast<playerFrame::box_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::box_tableDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->box_tableRowDeleting(this, (gcnew playerFrame::box_tableRowChangeEvent((cli::safe_cast<playerFrame::box_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::box_tableDataTable::Removebox_tableRow(playerFrame::box_tableRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  playerFrame::box_tableDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    playerFrame^  ds = (gcnew playerFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"box_tableDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline playerFrame::boxDataTable::boxDataTable() {
    this->TableName = L"box";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline playerFrame::boxDataTable::boxDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline playerFrame::boxDataTable::boxDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  playerFrame::boxDataTable::typeColumn::get() {
    return this->columntype;
}

inline ::System::Data::DataColumn^  playerFrame::boxDataTable::box_IdColumn::get() {
    return this->columnbox_Id;
}

inline ::System::Data::DataColumn^  playerFrame::boxDataTable::box_table_IdColumn::get() {
    return this->columnbox_table_Id;
}

inline ::System::Int32 playerFrame::boxDataTable::Count::get() {
    return this->Rows->Count;
}

inline playerFrame::boxRow^  playerFrame::boxDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<playerFrame::boxRow^  >(this->Rows[index]));
}

inline ::System::Void playerFrame::boxDataTable::AddboxRow(playerFrame::boxRow^  row) {
    this->Rows->Add(row);
}

inline playerFrame::boxRow^  playerFrame::boxDataTable::AddboxRow(System::Int32 type, playerFrame::box_tableRow^  parentbox_tableRowBybox_table_box) {
    playerFrame::boxRow^  rowboxRow = (cli::safe_cast<playerFrame::boxRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(3) {type, nullptr, nullptr};
    if (parentbox_tableRowBybox_table_box != nullptr) {
        columnValuesArray[2] = parentbox_tableRowBybox_table_box[0];
    }
    rowboxRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowboxRow);
    return rowboxRow;
}

inline ::System::Collections::IEnumerator^  playerFrame::boxDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  playerFrame::boxDataTable::Clone() {
    playerFrame::boxDataTable^  cln = (cli::safe_cast<playerFrame::boxDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  playerFrame::boxDataTable::CreateInstance() {
    return (gcnew playerFrame::boxDataTable());
}

inline ::System::Void playerFrame::boxDataTable::InitVars() {
    this->columntype = __super::Columns[L"type"];
    this->columnbox_Id = __super::Columns[L"box_Id"];
    this->columnbox_table_Id = __super::Columns[L"box_table_Id"];
}

inline ::System::Void playerFrame::boxDataTable::InitClass() {
    this->columntype = (gcnew ::System::Data::DataColumn(L"type", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columntype);
    this->columnbox_Id = (gcnew ::System::Data::DataColumn(L"box_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnbox_Id);
    this->columnbox_table_Id = (gcnew ::System::Data::DataColumn(L"box_table_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnbox_table_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnbox_Id}, 
            true)));
    this->columntype->Namespace = L"";
    this->columntype->DefaultValue = static_cast<System::Int32>(1);
    this->columnbox_Id->AutoIncrement = true;
    this->columnbox_Id->AllowDBNull = false;
    this->columnbox_Id->Unique = true;
}

inline playerFrame::boxRow^  playerFrame::boxDataTable::NewboxRow() {
    return (cli::safe_cast<playerFrame::boxRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  playerFrame::boxDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew playerFrame::boxRow(builder));
}

inline ::System::Type^  playerFrame::boxDataTable::GetRowType() {
    return playerFrame::boxRow::typeid;
}

inline ::System::Void playerFrame::boxDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->boxRowChanged(this, (gcnew playerFrame::boxRowChangeEvent((cli::safe_cast<playerFrame::boxRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void playerFrame::boxDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->boxRowChanging(this, (gcnew playerFrame::boxRowChangeEvent((cli::safe_cast<playerFrame::boxRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void playerFrame::boxDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->boxRowDeleted(this, (gcnew playerFrame::boxRowChangeEvent((cli::safe_cast<playerFrame::boxRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void playerFrame::boxDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->boxRowDeleting(this, (gcnew playerFrame::boxRowChangeEvent((cli::safe_cast<playerFrame::boxRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void playerFrame::boxDataTable::RemoveboxRow(playerFrame::boxRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  playerFrame::boxDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    playerFrame^  ds = (gcnew playerFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"boxDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline playerFrame::rectDataTable::rectDataTable() {
    this->TableName = L"rect";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline playerFrame::rectDataTable::rectDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline playerFrame::rectDataTable::rectDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  playerFrame::rectDataTable::tColumn::get() {
    return this->columnt;
}

inline ::System::Data::DataColumn^  playerFrame::rectDataTable::lColumn::get() {
    return this->columnl;
}

inline ::System::Data::DataColumn^  playerFrame::rectDataTable::bColumn::get() {
    return this->columnb;
}

inline ::System::Data::DataColumn^  playerFrame::rectDataTable::rColumn::get() {
    return this->columnr;
}

inline ::System::Data::DataColumn^  playerFrame::rectDataTable::box_IdColumn::get() {
    return this->columnbox_Id;
}

inline ::System::Int32 playerFrame::rectDataTable::Count::get() {
    return this->Rows->Count;
}

inline playerFrame::rectRow^  playerFrame::rectDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<playerFrame::rectRow^  >(this->Rows[index]));
}

inline ::System::Void playerFrame::rectDataTable::AddrectRow(playerFrame::rectRow^  row) {
    this->Rows->Add(row);
}

inline playerFrame::rectRow^  playerFrame::rectDataTable::AddrectRow(System::Single t, System::Single l, System::Single b, 
            System::Single r, playerFrame::boxRow^  parentboxRowBybox_rect) {
    playerFrame::rectRow^  rowrectRow = (cli::safe_cast<playerFrame::rectRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(5) {t, l, b, r, nullptr};
    if (parentboxRowBybox_rect != nullptr) {
        columnValuesArray[4] = parentboxRowBybox_rect[1];
    }
    rowrectRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowrectRow);
    return rowrectRow;
}

inline ::System::Collections::IEnumerator^  playerFrame::rectDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  playerFrame::rectDataTable::Clone() {
    playerFrame::rectDataTable^  cln = (cli::safe_cast<playerFrame::rectDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  playerFrame::rectDataTable::CreateInstance() {
    return (gcnew playerFrame::rectDataTable());
}

inline ::System::Void playerFrame::rectDataTable::InitVars() {
    this->columnt = __super::Columns[L"t"];
    this->columnl = __super::Columns[L"l"];
    this->columnb = __super::Columns[L"b"];
    this->columnr = __super::Columns[L"r"];
    this->columnbox_Id = __super::Columns[L"box_Id"];
}

inline ::System::Void playerFrame::rectDataTable::InitClass() {
    this->columnt = (gcnew ::System::Data::DataColumn(L"t", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columnt);
    this->columnl = (gcnew ::System::Data::DataColumn(L"l", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columnl);
    this->columnb = (gcnew ::System::Data::DataColumn(L"b", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columnb);
    this->columnr = (gcnew ::System::Data::DataColumn(L"r", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columnr);
    this->columnbox_Id = (gcnew ::System::Data::DataColumn(L"box_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnbox_Id);
    this->columnt->Namespace = L"";
    this->columnl->Namespace = L"";
    this->columnb->Namespace = L"";
    this->columnr->Namespace = L"";
}

inline playerFrame::rectRow^  playerFrame::rectDataTable::NewrectRow() {
    return (cli::safe_cast<playerFrame::rectRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  playerFrame::rectDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew playerFrame::rectRow(builder));
}

inline ::System::Type^  playerFrame::rectDataTable::GetRowType() {
    return playerFrame::rectRow::typeid;
}

inline ::System::Void playerFrame::rectDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->rectRowChanged(this, (gcnew playerFrame::rectRowChangeEvent((cli::safe_cast<playerFrame::rectRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::rectDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->rectRowChanging(this, (gcnew playerFrame::rectRowChangeEvent((cli::safe_cast<playerFrame::rectRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::rectDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->rectRowDeleted(this, (gcnew playerFrame::rectRowChangeEvent((cli::safe_cast<playerFrame::rectRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::rectDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->rectRowDeleting(this, (gcnew playerFrame::rectRowChangeEvent((cli::safe_cast<playerFrame::rectRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void playerFrame::rectDataTable::RemoverectRow(playerFrame::rectRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  playerFrame::rectDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    playerFrame^  ds = (gcnew playerFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"rectDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline playerFrame::player_infoRow::player_infoRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableplayer_info = (cli::safe_cast<playerFrame::player_infoDataTable^  >(this->Table));
}

inline System::Int32 playerFrame::player_infoRow::player_info_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableplayer_info->player_info_IdColumn]));
}
inline System::Void playerFrame::player_infoRow::player_info_Id::set(System::Int32 value) {
    this[this->tableplayer_info->player_info_IdColumn] = value;
}

inline cli::array< playerFrame::skin_tableRow^  >^  playerFrame::player_infoRow::Getskin_tableRows() {
    if (this->Table->ChildRelations[L"player_info_skin_table"] == nullptr) {
        return gcnew cli::array< playerFrame::skin_tableRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< playerFrame::skin_tableRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"player_info_skin_table"])));
    }
}

inline cli::array< playerFrame::skill_tableRow^  >^  playerFrame::player_infoRow::Getskill_tableRows() {
    if (this->Table->ChildRelations[L"player_info_skill_table"] == nullptr) {
        return gcnew cli::array< playerFrame::skill_tableRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< playerFrame::skill_tableRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"player_info_skill_table"])));
    }
}


inline playerFrame::skin_tableRow::skin_tableRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableskin_table = (cli::safe_cast<playerFrame::skin_tableDataTable^  >(this->Table));
}

inline System::Int32 playerFrame::skin_tableRow::skin_table_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableskin_table->skin_table_IdColumn]));
}
inline System::Void playerFrame::skin_tableRow::skin_table_Id::set(System::Int32 value) {
    this[this->tableskin_table->skin_table_IdColumn] = value;
}

inline System::Int32 playerFrame::skin_tableRow::player_info_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableskin_table->player_info_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“skin_table”中列“player_info_Id”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::skin_tableRow::player_info_Id::set(System::Int32 value) {
    this[this->tableskin_table->player_info_IdColumn] = value;
}

inline playerFrame::player_infoRow^  playerFrame::skin_tableRow::player_infoRow::get() {
    return (cli::safe_cast<playerFrame::player_infoRow^  >(this->GetParentRow(this->Table->ParentRelations[L"player_info_skin_table"])));
}
inline System::Void playerFrame::skin_tableRow::player_infoRow::set(playerFrame::player_infoRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"player_info_skin_table"]);
}

inline ::System::Boolean playerFrame::skin_tableRow::Isplayer_info_IdNull() {
    return this->IsNull(this->tableskin_table->player_info_IdColumn);
}

inline ::System::Void playerFrame::skin_tableRow::Setplayer_info_IdNull() {
    this[this->tableskin_table->player_info_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< playerFrame::skinRow^  >^  playerFrame::skin_tableRow::GetskinRows() {
    if (this->Table->ChildRelations[L"skin_table_skin"] == nullptr) {
        return gcnew cli::array< playerFrame::skinRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< playerFrame::skinRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"skin_table_skin"])));
    }
}


inline playerFrame::skinRow::skinRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableskin = (cli::safe_cast<playerFrame::skinDataTable^  >(this->Table));
}

inline System::String^  playerFrame::skinRow::name::get() {
    return (cli::safe_cast<::System::String^  >(this[this->tableskin->nameColumn]));
}
inline System::Void playerFrame::skinRow::name::set(System::String^  value) {
    this[this->tableskin->nameColumn] = value;
}

inline System::Int32 playerFrame::skinRow::skin_table_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableskin->skin_table_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“skin”中列“skin_table_Id”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::skinRow::skin_table_Id::set(System::Int32 value) {
    this[this->tableskin->skin_table_IdColumn] = value;
}

inline playerFrame::skin_tableRow^  playerFrame::skinRow::skin_tableRow::get() {
    return (cli::safe_cast<playerFrame::skin_tableRow^  >(this->GetParentRow(this->Table->ParentRelations[L"skin_table_skin"])));
}
inline System::Void playerFrame::skinRow::skin_tableRow::set(playerFrame::skin_tableRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"skin_table_skin"]);
}

inline ::System::Boolean playerFrame::skinRow::Isskin_table_IdNull() {
    return this->IsNull(this->tableskin->skin_table_IdColumn);
}

inline ::System::Void playerFrame::skinRow::Setskin_table_IdNull() {
    this[this->tableskin->skin_table_IdColumn] = ::System::Convert::DBNull;
}


inline playerFrame::skill_tableRow::skill_tableRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableskill_table = (cli::safe_cast<playerFrame::skill_tableDataTable^  >(this->Table));
}

inline System::Int32 playerFrame::skill_tableRow::skill_table_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableskill_table->skill_table_IdColumn]));
}
inline System::Void playerFrame::skill_tableRow::skill_table_Id::set(System::Int32 value) {
    this[this->tableskill_table->skill_table_IdColumn] = value;
}

inline System::Int32 playerFrame::skill_tableRow::player_info_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableskill_table->player_info_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“skill_table”中列“player_info_Id”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::skill_tableRow::player_info_Id::set(System::Int32 value) {
    this[this->tableskill_table->player_info_IdColumn] = value;
}

inline playerFrame::player_infoRow^  playerFrame::skill_tableRow::player_infoRow::get() {
    return (cli::safe_cast<playerFrame::player_infoRow^  >(this->GetParentRow(this->Table->ParentRelations[L"player_info_skill_table"])));
}
inline System::Void playerFrame::skill_tableRow::player_infoRow::set(playerFrame::player_infoRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"player_info_skill_table"]);
}

inline ::System::Boolean playerFrame::skill_tableRow::Isplayer_info_IdNull() {
    return this->IsNull(this->tableskill_table->player_info_IdColumn);
}

inline ::System::Void playerFrame::skill_tableRow::Setplayer_info_IdNull() {
    this[this->tableskill_table->player_info_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< playerFrame::skillRow^  >^  playerFrame::skill_tableRow::GetskillRows() {
    if (this->Table->ChildRelations[L"skill_table_skill"] == nullptr) {
        return gcnew cli::array< playerFrame::skillRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< playerFrame::skillRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"skill_table_skill"])));
    }
}


inline playerFrame::skillRow::skillRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableskill = (cli::safe_cast<playerFrame::skillDataTable^  >(this->Table));
}

inline System::String^  playerFrame::skillRow::eka::get() {
    return (cli::safe_cast<::System::String^  >(this[this->tableskill->ekaColumn]));
}
inline System::Void playerFrame::skillRow::eka::set(System::String^  value) {
    this[this->tableskill->ekaColumn] = value;
}

inline System::String^  playerFrame::skillRow::as::get() {
    try {
        return (cli::safe_cast<::System::String^  >(this[this->tableskill->asColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“skill”中列“as”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::skillRow::as::set(System::String^  value) {
    this[this->tableskill->asColumn] = value;
}

inline System::String^  playerFrame::skillRow::ssse::get() {
    try {
        return (cli::safe_cast<::System::String^  >(this[this->tableskill->ssseColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“skill”中列“ssse”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::skillRow::ssse::set(System::String^  value) {
    this[this->tableskill->ssseColumn] = value;
}

inline System::Boolean playerFrame::skillRow::savable::get() {
    try {
        return (cli::safe_cast<::System::Boolean >(this[this->tableskill->savableColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“skill”中列“savable”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::skillRow::savable::set(System::Boolean value) {
    this[this->tableskill->savableColumn] = value;
}

inline System::Int32 playerFrame::skillRow::skill_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableskill->skill_IdColumn]));
}
inline System::Void playerFrame::skillRow::skill_Id::set(System::Int32 value) {
    this[this->tableskill->skill_IdColumn] = value;
}

inline System::Int32 playerFrame::skillRow::skill_table_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableskill->skill_table_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“skill”中列“skill_table_Id”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::skillRow::skill_table_Id::set(System::Int32 value) {
    this[this->tableskill->skill_table_IdColumn] = value;
}

inline playerFrame::skill_tableRow^  playerFrame::skillRow::skill_tableRow::get() {
    return (cli::safe_cast<playerFrame::skill_tableRow^  >(this->GetParentRow(this->Table->ParentRelations[L"skill_table_skill"])));
}
inline System::Void playerFrame::skillRow::skill_tableRow::set(playerFrame::skill_tableRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"skill_table_skill"]);
}

inline ::System::Boolean playerFrame::skillRow::IsasNull() {
    return this->IsNull(this->tableskill->asColumn);
}

inline ::System::Void playerFrame::skillRow::SetasNull() {
    this[this->tableskill->asColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean playerFrame::skillRow::IsssseNull() {
    return this->IsNull(this->tableskill->ssseColumn);
}

inline ::System::Void playerFrame::skillRow::SetssseNull() {
    this[this->tableskill->ssseColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean playerFrame::skillRow::IssavableNull() {
    return this->IsNull(this->tableskill->savableColumn);
}

inline ::System::Void playerFrame::skillRow::SetsavableNull() {
    this[this->tableskill->savableColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean playerFrame::skillRow::Isskill_table_IdNull() {
    return this->IsNull(this->tableskill->skill_table_IdColumn);
}

inline ::System::Void playerFrame::skillRow::Setskill_table_IdNull() {
    this[this->tableskill->skill_table_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< playerFrame::object_tableRow^  >^  playerFrame::skillRow::Getobject_tableRows() {
    if (this->Table->ChildRelations[L"skill_object_table"] == nullptr) {
        return gcnew cli::array< playerFrame::object_tableRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< playerFrame::object_tableRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"skill_object_table"])));
    }
}


inline playerFrame::object_tableRow::object_tableRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableobject_table = (cli::safe_cast<playerFrame::object_tableDataTable^  >(this->Table));
}

inline System::Int32 playerFrame::object_tableRow::object_table_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableobject_table->object_table_IdColumn]));
}
inline System::Void playerFrame::object_tableRow::object_table_Id::set(System::Int32 value) {
    this[this->tableobject_table->object_table_IdColumn] = value;
}

inline System::Int32 playerFrame::object_tableRow::skill_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableobject_table->skill_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“object_table”中列“skill_Id”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::object_tableRow::skill_Id::set(System::Int32 value) {
    this[this->tableobject_table->skill_IdColumn] = value;
}

inline playerFrame::skillRow^  playerFrame::object_tableRow::skillRow::get() {
    return (cli::safe_cast<playerFrame::skillRow^  >(this->GetParentRow(this->Table->ParentRelations[L"skill_object_table"])));
}
inline System::Void playerFrame::object_tableRow::skillRow::set(playerFrame::skillRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"skill_object_table"]);
}

inline ::System::Boolean playerFrame::object_tableRow::Isskill_IdNull() {
    return this->IsNull(this->tableobject_table->skill_IdColumn);
}

inline ::System::Void playerFrame::object_tableRow::Setskill_IdNull() {
    this[this->tableobject_table->skill_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< playerFrame::objectRow^  >^  playerFrame::object_tableRow::GetobjectRows() {
    if (this->Table->ChildRelations[L"object_table_object"] == nullptr) {
        return gcnew cli::array< playerFrame::objectRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< playerFrame::objectRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"object_table_object"])));
    }
}


inline playerFrame::objectRow::objectRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableobject = (cli::safe_cast<playerFrame::objectDataTable^  >(this->Table));
}

inline System::Int32 playerFrame::objectRow::id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableobject->idColumn]));
}
inline System::Void playerFrame::objectRow::id::set(System::Int32 value) {
    this[this->tableobject->idColumn] = value;
}

inline System::Int32 playerFrame::objectRow::object_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableobject->object_IdColumn]));
}
inline System::Void playerFrame::objectRow::object_Id::set(System::Int32 value) {
    this[this->tableobject->object_IdColumn] = value;
}

inline System::Int32 playerFrame::objectRow::object_table_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableobject->object_table_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“object”中列“object_table_Id”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::objectRow::object_table_Id::set(System::Int32 value) {
    this[this->tableobject->object_table_IdColumn] = value;
}

inline playerFrame::object_tableRow^  playerFrame::objectRow::object_tableRow::get() {
    return (cli::safe_cast<playerFrame::object_tableRow^  >(this->GetParentRow(this->Table->ParentRelations[L"object_table_object"])));
}
inline System::Void playerFrame::objectRow::object_tableRow::set(playerFrame::object_tableRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"object_table_object"]);
}

inline ::System::Boolean playerFrame::objectRow::Isobject_table_IdNull() {
    return this->IsNull(this->tableobject->object_table_IdColumn);
}

inline ::System::Void playerFrame::objectRow::Setobject_table_IdNull() {
    this[this->tableobject->object_table_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< playerFrame::frame_tableRow^  >^  playerFrame::objectRow::Getframe_tableRows() {
    if (this->Table->ChildRelations[L"object_frame_table"] == nullptr) {
        return gcnew cli::array< playerFrame::frame_tableRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< playerFrame::frame_tableRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"object_frame_table"])));
    }
}


inline playerFrame::frame_tableRow::frame_tableRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableframe_table = (cli::safe_cast<playerFrame::frame_tableDataTable^  >(this->Table));
}

inline System::Int32 playerFrame::frame_tableRow::frame_table_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableframe_table->frame_table_IdColumn]));
}
inline System::Void playerFrame::frame_tableRow::frame_table_Id::set(System::Int32 value) {
    this[this->tableframe_table->frame_table_IdColumn] = value;
}

inline System::Int32 playerFrame::frame_tableRow::object_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableframe_table->object_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“frame_table”中列“object_Id”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::frame_tableRow::object_Id::set(System::Int32 value) {
    this[this->tableframe_table->object_IdColumn] = value;
}

inline playerFrame::objectRow^  playerFrame::frame_tableRow::objectRow::get() {
    return (cli::safe_cast<playerFrame::objectRow^  >(this->GetParentRow(this->Table->ParentRelations[L"object_frame_table"])));
}
inline System::Void playerFrame::frame_tableRow::objectRow::set(playerFrame::objectRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"object_frame_table"]);
}

inline ::System::Boolean playerFrame::frame_tableRow::Isobject_IdNull() {
    return this->IsNull(this->tableframe_table->object_IdColumn);
}

inline ::System::Void playerFrame::frame_tableRow::Setobject_IdNull() {
    this[this->tableframe_table->object_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< playerFrame::frameRow^  >^  playerFrame::frame_tableRow::GetframeRows() {
    if (this->Table->ChildRelations[L"frame_table_frame"] == nullptr) {
        return gcnew cli::array< playerFrame::frameRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< playerFrame::frameRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"frame_table_frame"])));
    }
}


inline playerFrame::frameRow::frameRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableframe = (cli::safe_cast<playerFrame::frameDataTable^  >(this->Table));
}

inline System::Int32 playerFrame::frameRow::id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableframe->idColumn]));
}
inline System::Void playerFrame::frameRow::id::set(System::Int32 value) {
    this[this->tableframe->idColumn] = value;
}

inline System::Int32 playerFrame::frameRow::frame_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableframe->frame_IdColumn]));
}
inline System::Void playerFrame::frameRow::frame_Id::set(System::Int32 value) {
    this[this->tableframe->frame_IdColumn] = value;
}

inline System::Int32 playerFrame::frameRow::frame_table_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableframe->frame_table_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“frame”中列“frame_table_Id”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::frameRow::frame_table_Id::set(System::Int32 value) {
    this[this->tableframe->frame_table_IdColumn] = value;
}

inline playerFrame::frame_tableRow^  playerFrame::frameRow::frame_tableRow::get() {
    return (cli::safe_cast<playerFrame::frame_tableRow^  >(this->GetParentRow(this->Table->ParentRelations[L"frame_table_frame"])));
}
inline System::Void playerFrame::frameRow::frame_tableRow::set(playerFrame::frame_tableRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"frame_table_frame"]);
}

inline ::System::Boolean playerFrame::frameRow::Isframe_table_IdNull() {
    return this->IsNull(this->tableframe->frame_table_IdColumn);
}

inline ::System::Void playerFrame::frameRow::Setframe_table_IdNull() {
    this[this->tableframe->frame_table_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< playerFrame::pointRow^  >^  playerFrame::frameRow::GetpointRows() {
    if (this->Table->ChildRelations[L"frame_point"] == nullptr) {
        return gcnew cli::array< playerFrame::pointRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< playerFrame::pointRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"frame_point"])));
    }
}

inline cli::array< playerFrame::box_tableRow^  >^  playerFrame::frameRow::Getbox_tableRows() {
    if (this->Table->ChildRelations[L"frame_box_table"] == nullptr) {
        return gcnew cli::array< playerFrame::box_tableRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< playerFrame::box_tableRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"frame_box_table"])));
    }
}


inline playerFrame::pointRow::pointRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tablepoint = (cli::safe_cast<playerFrame::pointDataTable^  >(this->Table));
}

inline System::Single playerFrame::pointRow::x::get() {
    try {
        return (cli::safe_cast<::System::Single >(this[this->tablepoint->xColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“point”中列“x”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::pointRow::x::set(System::Single value) {
    this[this->tablepoint->xColumn] = value;
}

inline System::Single playerFrame::pointRow::y::get() {
    try {
        return (cli::safe_cast<::System::Single >(this[this->tablepoint->yColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“point”中列“y”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::pointRow::y::set(System::Single value) {
    this[this->tablepoint->yColumn] = value;
}

inline System::Int32 playerFrame::pointRow::frame_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tablepoint->frame_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“point”中列“frame_Id”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::pointRow::frame_Id::set(System::Int32 value) {
    this[this->tablepoint->frame_IdColumn] = value;
}

inline playerFrame::frameRow^  playerFrame::pointRow::frameRow::get() {
    return (cli::safe_cast<playerFrame::frameRow^  >(this->GetParentRow(this->Table->ParentRelations[L"frame_point"])));
}
inline System::Void playerFrame::pointRow::frameRow::set(playerFrame::frameRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"frame_point"]);
}

inline ::System::Boolean playerFrame::pointRow::IsxNull() {
    return this->IsNull(this->tablepoint->xColumn);
}

inline ::System::Void playerFrame::pointRow::SetxNull() {
    this[this->tablepoint->xColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean playerFrame::pointRow::IsyNull() {
    return this->IsNull(this->tablepoint->yColumn);
}

inline ::System::Void playerFrame::pointRow::SetyNull() {
    this[this->tablepoint->yColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean playerFrame::pointRow::Isframe_IdNull() {
    return this->IsNull(this->tablepoint->frame_IdColumn);
}

inline ::System::Void playerFrame::pointRow::Setframe_IdNull() {
    this[this->tablepoint->frame_IdColumn] = ::System::Convert::DBNull;
}


inline playerFrame::box_tableRow::box_tableRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tablebox_table = (cli::safe_cast<playerFrame::box_tableDataTable^  >(this->Table));
}

inline System::Int32 playerFrame::box_tableRow::box_table_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tablebox_table->box_table_IdColumn]));
}
inline System::Void playerFrame::box_tableRow::box_table_Id::set(System::Int32 value) {
    this[this->tablebox_table->box_table_IdColumn] = value;
}

inline System::Int32 playerFrame::box_tableRow::frame_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tablebox_table->frame_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“box_table”中列“frame_Id”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::box_tableRow::frame_Id::set(System::Int32 value) {
    this[this->tablebox_table->frame_IdColumn] = value;
}

inline playerFrame::frameRow^  playerFrame::box_tableRow::frameRow::get() {
    return (cli::safe_cast<playerFrame::frameRow^  >(this->GetParentRow(this->Table->ParentRelations[L"frame_box_table"])));
}
inline System::Void playerFrame::box_tableRow::frameRow::set(playerFrame::frameRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"frame_box_table"]);
}

inline ::System::Boolean playerFrame::box_tableRow::Isframe_IdNull() {
    return this->IsNull(this->tablebox_table->frame_IdColumn);
}

inline ::System::Void playerFrame::box_tableRow::Setframe_IdNull() {
    this[this->tablebox_table->frame_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< playerFrame::boxRow^  >^  playerFrame::box_tableRow::GetboxRows() {
    if (this->Table->ChildRelations[L"box_table_box"] == nullptr) {
        return gcnew cli::array< playerFrame::boxRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< playerFrame::boxRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"box_table_box"])));
    }
}


inline playerFrame::boxRow::boxRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tablebox = (cli::safe_cast<playerFrame::boxDataTable^  >(this->Table));
}

inline System::Int32 playerFrame::boxRow::type::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tablebox->typeColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“box”中列“type”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::boxRow::type::set(System::Int32 value) {
    this[this->tablebox->typeColumn] = value;
}

inline System::Int32 playerFrame::boxRow::box_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tablebox->box_IdColumn]));
}
inline System::Void playerFrame::boxRow::box_Id::set(System::Int32 value) {
    this[this->tablebox->box_IdColumn] = value;
}

inline System::Int32 playerFrame::boxRow::box_table_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tablebox->box_table_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“box”中列“box_table_Id”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::boxRow::box_table_Id::set(System::Int32 value) {
    this[this->tablebox->box_table_IdColumn] = value;
}

inline playerFrame::box_tableRow^  playerFrame::boxRow::box_tableRow::get() {
    return (cli::safe_cast<playerFrame::box_tableRow^  >(this->GetParentRow(this->Table->ParentRelations[L"box_table_box"])));
}
inline System::Void playerFrame::boxRow::box_tableRow::set(playerFrame::box_tableRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"box_table_box"]);
}

inline ::System::Boolean playerFrame::boxRow::IstypeNull() {
    return this->IsNull(this->tablebox->typeColumn);
}

inline ::System::Void playerFrame::boxRow::SettypeNull() {
    this[this->tablebox->typeColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean playerFrame::boxRow::Isbox_table_IdNull() {
    return this->IsNull(this->tablebox->box_table_IdColumn);
}

inline ::System::Void playerFrame::boxRow::Setbox_table_IdNull() {
    this[this->tablebox->box_table_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< playerFrame::rectRow^  >^  playerFrame::boxRow::GetrectRows() {
    if (this->Table->ChildRelations[L"box_rect"] == nullptr) {
        return gcnew cli::array< playerFrame::rectRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< playerFrame::rectRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"box_rect"])));
    }
}


inline playerFrame::rectRow::rectRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tablerect = (cli::safe_cast<playerFrame::rectDataTable^  >(this->Table));
}

inline System::Single playerFrame::rectRow::t::get() {
    try {
        return (cli::safe_cast<::System::Single >(this[this->tablerect->tColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“rect”中列“t”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::rectRow::t::set(System::Single value) {
    this[this->tablerect->tColumn] = value;
}

inline System::Single playerFrame::rectRow::l::get() {
    try {
        return (cli::safe_cast<::System::Single >(this[this->tablerect->lColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“rect”中列“l”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::rectRow::l::set(System::Single value) {
    this[this->tablerect->lColumn] = value;
}

inline System::Single playerFrame::rectRow::b::get() {
    try {
        return (cli::safe_cast<::System::Single >(this[this->tablerect->bColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“rect”中列“b”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::rectRow::b::set(System::Single value) {
    this[this->tablerect->bColumn] = value;
}

inline System::Single playerFrame::rectRow::r::get() {
    try {
        return (cli::safe_cast<::System::Single >(this[this->tablerect->rColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“rect”中列“r”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::rectRow::r::set(System::Single value) {
    this[this->tablerect->rColumn] = value;
}

inline System::Int32 playerFrame::rectRow::box_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tablerect->box_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“rect”中列“box_Id”的值为 DBNull。", e));
    }
}
inline System::Void playerFrame::rectRow::box_Id::set(System::Int32 value) {
    this[this->tablerect->box_IdColumn] = value;
}

inline playerFrame::boxRow^  playerFrame::rectRow::boxRow::get() {
    return (cli::safe_cast<playerFrame::boxRow^  >(this->GetParentRow(this->Table->ParentRelations[L"box_rect"])));
}
inline System::Void playerFrame::rectRow::boxRow::set(playerFrame::boxRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"box_rect"]);
}

inline ::System::Boolean playerFrame::rectRow::IstNull() {
    return this->IsNull(this->tablerect->tColumn);
}

inline ::System::Void playerFrame::rectRow::SettNull() {
    this[this->tablerect->tColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean playerFrame::rectRow::IslNull() {
    return this->IsNull(this->tablerect->lColumn);
}

inline ::System::Void playerFrame::rectRow::SetlNull() {
    this[this->tablerect->lColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean playerFrame::rectRow::IsbNull() {
    return this->IsNull(this->tablerect->bColumn);
}

inline ::System::Void playerFrame::rectRow::SetbNull() {
    this[this->tablerect->bColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean playerFrame::rectRow::IsrNull() {
    return this->IsNull(this->tablerect->rColumn);
}

inline ::System::Void playerFrame::rectRow::SetrNull() {
    this[this->tablerect->rColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean playerFrame::rectRow::Isbox_IdNull() {
    return this->IsNull(this->tablerect->box_IdColumn);
}

inline ::System::Void playerFrame::rectRow::Setbox_IdNull() {
    this[this->tablerect->box_IdColumn] = ::System::Convert::DBNull;
}


inline playerFrame::player_infoRowChangeEvent::player_infoRowChangeEvent(playerFrame::player_infoRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline playerFrame::player_infoRow^  playerFrame::player_infoRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction playerFrame::player_infoRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline playerFrame::skin_tableRowChangeEvent::skin_tableRowChangeEvent(playerFrame::skin_tableRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline playerFrame::skin_tableRow^  playerFrame::skin_tableRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction playerFrame::skin_tableRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline playerFrame::skinRowChangeEvent::skinRowChangeEvent(playerFrame::skinRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline playerFrame::skinRow^  playerFrame::skinRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction playerFrame::skinRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline playerFrame::skill_tableRowChangeEvent::skill_tableRowChangeEvent(playerFrame::skill_tableRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline playerFrame::skill_tableRow^  playerFrame::skill_tableRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction playerFrame::skill_tableRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline playerFrame::skillRowChangeEvent::skillRowChangeEvent(playerFrame::skillRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline playerFrame::skillRow^  playerFrame::skillRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction playerFrame::skillRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline playerFrame::object_tableRowChangeEvent::object_tableRowChangeEvent(playerFrame::object_tableRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline playerFrame::object_tableRow^  playerFrame::object_tableRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction playerFrame::object_tableRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline playerFrame::objectRowChangeEvent::objectRowChangeEvent(playerFrame::objectRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline playerFrame::objectRow^  playerFrame::objectRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction playerFrame::objectRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline playerFrame::frame_tableRowChangeEvent::frame_tableRowChangeEvent(playerFrame::frame_tableRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline playerFrame::frame_tableRow^  playerFrame::frame_tableRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction playerFrame::frame_tableRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline playerFrame::frameRowChangeEvent::frameRowChangeEvent(playerFrame::frameRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline playerFrame::frameRow^  playerFrame::frameRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction playerFrame::frameRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline playerFrame::pointRowChangeEvent::pointRowChangeEvent(playerFrame::pointRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline playerFrame::pointRow^  playerFrame::pointRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction playerFrame::pointRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline playerFrame::box_tableRowChangeEvent::box_tableRowChangeEvent(playerFrame::box_tableRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline playerFrame::box_tableRow^  playerFrame::box_tableRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction playerFrame::box_tableRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline playerFrame::boxRowChangeEvent::boxRowChangeEvent(playerFrame::boxRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline playerFrame::boxRow^  playerFrame::boxRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction playerFrame::boxRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline playerFrame::rectRowChangeEvent::rectRowChangeEvent(playerFrame::rectRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline playerFrame::rectRow^  playerFrame::rectRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction playerFrame::rectRowChangeEvent::Action::get() {
    return this->eventAction;
}
