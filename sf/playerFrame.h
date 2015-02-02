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
ref class skillFrame;


/// <summary>
///Represents a strongly typed in-memory cache of data.
///</summary>
[System::Serializable, 
System::ComponentModel::DesignerCategoryAttribute(L"code"), 
System::ComponentModel::ToolboxItem(true), 
System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedDataSetSchema"), 
System::Xml::Serialization::XmlRootAttribute(L"skillFrame"), 
System::ComponentModel::Design::HelpKeywordAttribute(L"vs.data.DataSet")]
public ref class skillFrame : public ::System::Data::DataSet {
    public : ref class rectDataTable;
    public : ref class pointDataTable;
    public : ref class box_tableDataTable;
    public : ref class boxDataTable;
    public : ref class frame_tableDataTable;
    public : ref class frameDataTable;
    public : ref class skin_tableDataTable;
    public : ref class skinDataTable;
    public : ref class object_tableDataTable;
    public : ref class objectDataTable;
    public : ref class skill_tableDataTable;
    public : ref class skillDataTable;
    public : ref class player_infoDataTable;
    public : ref class rectRow;
    public : ref class pointRow;
    public : ref class box_tableRow;
    public : ref class boxRow;
    public : ref class frame_tableRow;
    public : ref class frameRow;
    public : ref class skin_tableRow;
    public : ref class skinRow;
    public : ref class object_tableRow;
    public : ref class objectRow;
    public : ref class skill_tableRow;
    public : ref class skillRow;
    public : ref class player_infoRow;
    public : ref class rectRowChangeEvent;
    public : ref class pointRowChangeEvent;
    public : ref class box_tableRowChangeEvent;
    public : ref class boxRowChangeEvent;
    public : ref class frame_tableRowChangeEvent;
    public : ref class frameRowChangeEvent;
    public : ref class skin_tableRowChangeEvent;
    public : ref class skinRowChangeEvent;
    public : ref class object_tableRowChangeEvent;
    public : ref class objectRowChangeEvent;
    public : ref class skill_tableRowChangeEvent;
    public : ref class skillRowChangeEvent;
    public : ref class player_infoRowChangeEvent;
    
    private: skillFrame::rectDataTable^  tablerect;
    
    private: skillFrame::pointDataTable^  tablepoint;
    
    private: skillFrame::box_tableDataTable^  tablebox_table;
    
    private: skillFrame::boxDataTable^  tablebox;
    
    private: skillFrame::frame_tableDataTable^  tableframe_table;
    
    private: skillFrame::frameDataTable^  tableframe;
    
    private: skillFrame::skin_tableDataTable^  tableskin_table;
    
    private: skillFrame::skinDataTable^  tableskin;
    
    private: skillFrame::object_tableDataTable^  tableobject_table;
    
    private: skillFrame::objectDataTable^  tableobject;
    
    private: skillFrame::skill_tableDataTable^  tableskill_table;
    
    private: skillFrame::skillDataTable^  tableskill;
    
    private: skillFrame::player_infoDataTable^  tableplayer_info;
    
    private: ::System::Data::DataRelation^  relationbox_rect;
    
    private: ::System::Data::DataRelation^  relationframe_point;
    
    private: ::System::Data::DataRelation^  relationframe_box_table;
    
    private: ::System::Data::DataRelation^  relationbox_table_box;
    
    private: ::System::Data::DataRelation^  relationobject_frame_table;
    
    private: ::System::Data::DataRelation^  relationframe_table_frame;
    
    private: ::System::Data::DataRelation^  relationplayer_info_skin_table;
    
    private: ::System::Data::DataRelation^  relationskin_table_skin;
    
    private: ::System::Data::DataRelation^  relationskill_object_table;
    
    private: ::System::Data::DataRelation^  relationobject_table_object;
    
    private: ::System::Data::DataRelation^  relationplayer_info_skill_table;
    
    private: ::System::Data::DataRelation^  relationskill_table_skill;
    
    private: ::System::Data::SchemaSerializationMode _schemaSerializationMode;
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void rectRowChangeEventHandler(::System::Object^  sender, skillFrame::rectRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void pointRowChangeEventHandler(::System::Object^  sender, skillFrame::pointRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void box_tableRowChangeEventHandler(::System::Object^  sender, skillFrame::box_tableRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void boxRowChangeEventHandler(::System::Object^  sender, skillFrame::boxRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void frame_tableRowChangeEventHandler(::System::Object^  sender, skillFrame::frame_tableRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void frameRowChangeEventHandler(::System::Object^  sender, skillFrame::frameRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void skin_tableRowChangeEventHandler(::System::Object^  sender, skillFrame::skin_tableRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void skinRowChangeEventHandler(::System::Object^  sender, skillFrame::skinRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void object_tableRowChangeEventHandler(::System::Object^  sender, skillFrame::object_tableRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void objectRowChangeEventHandler(::System::Object^  sender, skillFrame::objectRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void skill_tableRowChangeEventHandler(::System::Object^  sender, skillFrame::skill_tableRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void skillRowChangeEventHandler(::System::Object^  sender, skillFrame::skillRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void player_infoRowChangeEventHandler(::System::Object^  sender, skillFrame::player_infoRowChangeEvent^  e);
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    skillFrame();
    protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    skillFrame(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property skillFrame::rectDataTable^  rect {
        skillFrame::rectDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property skillFrame::pointDataTable^  point {
        skillFrame::pointDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property skillFrame::box_tableDataTable^  box_table {
        skillFrame::box_tableDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property skillFrame::boxDataTable^  box {
        skillFrame::boxDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property skillFrame::frame_tableDataTable^  frame_table {
        skillFrame::frame_tableDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property skillFrame::frameDataTable^  frame {
        skillFrame::frameDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property skillFrame::skin_tableDataTable^  skin_table {
        skillFrame::skin_tableDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property skillFrame::skinDataTable^  skin {
        skillFrame::skinDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property skillFrame::object_tableDataTable^  object_table {
        skillFrame::object_tableDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property skillFrame::objectDataTable^  object {
        skillFrame::objectDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property skillFrame::skill_tableDataTable^  skill_table {
        skillFrame::skill_tableDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property skillFrame::skillDataTable^  skill {
        skillFrame::skillDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property skillFrame::player_infoDataTable^  player_info {
        skillFrame::player_infoDataTable^  get();
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
    ::System::Boolean ShouldSerializerect();
    
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
    ::System::Boolean ShouldSerializeframe_table();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeframe();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeskin_table();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeskin();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeobject_table();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeobject();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeskill_table();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeskill();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeplayer_info();
    
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
    ref class rectDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnt;
        
        private: ::System::Data::DataColumn^  columnl;
        
        private: ::System::Data::DataColumn^  columnb;
        
        private: ::System::Data::DataColumn^  columnr;
        
        private: ::System::Data::DataColumn^  columnbox_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::rectRowChangeEventHandler^  rectRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::rectRowChangeEventHandler^  rectRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::rectRowChangeEventHandler^  rectRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::rectRowChangeEventHandler^  rectRowDeleted;
        
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
        property skillFrame::rectRow^  default [::System::Int32 ] {
            skillFrame::rectRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddrectRow(skillFrame::rectRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillFrame::rectRow^  AddrectRow(System::Single t, System::Single l, System::Single b, System::Single r, skillFrame::boxRow^  parentboxRowBybox_rect);
        
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
        skillFrame::rectRow^  NewrectRow();
        
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
        ::System::Void RemoverectRow(skillFrame::rectRow^  row);
        
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
        event skillFrame::pointRowChangeEventHandler^  pointRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::pointRowChangeEventHandler^  pointRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::pointRowChangeEventHandler^  pointRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::pointRowChangeEventHandler^  pointRowDeleted;
        
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
        property skillFrame::pointRow^  default [::System::Int32 ] {
            skillFrame::pointRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddpointRow(skillFrame::pointRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillFrame::pointRow^  AddpointRow(System::Single x, System::Single y, skillFrame::frameRow^  parentframeRowByframe_point);
        
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
        skillFrame::pointRow^  NewpointRow();
        
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
        ::System::Void RemovepointRow(skillFrame::pointRow^  row);
        
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
        event skillFrame::box_tableRowChangeEventHandler^  box_tableRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::box_tableRowChangeEventHandler^  box_tableRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::box_tableRowChangeEventHandler^  box_tableRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::box_tableRowChangeEventHandler^  box_tableRowDeleted;
        
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
        property skillFrame::box_tableRow^  default [::System::Int32 ] {
            skillFrame::box_tableRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Addbox_tableRow(skillFrame::box_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillFrame::box_tableRow^  Addbox_tableRow(skillFrame::frameRow^  parentframeRowByframe_box_table);
        
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
        skillFrame::box_tableRow^  Newbox_tableRow();
        
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
        ::System::Void Removebox_tableRow(skillFrame::box_tableRow^  row);
        
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
        event skillFrame::boxRowChangeEventHandler^  boxRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::boxRowChangeEventHandler^  boxRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::boxRowChangeEventHandler^  boxRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::boxRowChangeEventHandler^  boxRowDeleted;
        
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
        property skillFrame::boxRow^  default [::System::Int32 ] {
            skillFrame::boxRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddboxRow(skillFrame::boxRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillFrame::boxRow^  AddboxRow(System::Int32 type, skillFrame::box_tableRow^  parentbox_tableRowBybox_table_box);
        
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
        skillFrame::boxRow^  NewboxRow();
        
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
        ::System::Void RemoveboxRow(skillFrame::boxRow^  row);
        
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
        event skillFrame::frame_tableRowChangeEventHandler^  frame_tableRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::frame_tableRowChangeEventHandler^  frame_tableRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::frame_tableRowChangeEventHandler^  frame_tableRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::frame_tableRowChangeEventHandler^  frame_tableRowDeleted;
        
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
        property skillFrame::frame_tableRow^  default [::System::Int32 ] {
            skillFrame::frame_tableRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Addframe_tableRow(skillFrame::frame_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillFrame::frame_tableRow^  Addframe_tableRow(skillFrame::objectRow^  parentobjectRowByobject_frame_table);
        
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
        skillFrame::frame_tableRow^  Newframe_tableRow();
        
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
        ::System::Void Removeframe_tableRow(skillFrame::frame_tableRow^  row);
        
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
        event skillFrame::frameRowChangeEventHandler^  frameRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::frameRowChangeEventHandler^  frameRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::frameRowChangeEventHandler^  frameRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::frameRowChangeEventHandler^  frameRowDeleted;
        
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
        property skillFrame::frameRow^  default [::System::Int32 ] {
            skillFrame::frameRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddframeRow(skillFrame::frameRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillFrame::frameRow^  AddframeRow(System::Int32 id, skillFrame::frame_tableRow^  parentframe_tableRowByframe_table_frame);
        
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
        skillFrame::frameRow^  NewframeRow();
        
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
        ::System::Void RemoveframeRow(skillFrame::frameRow^  row);
        
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
        event skillFrame::skin_tableRowChangeEventHandler^  skin_tableRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::skin_tableRowChangeEventHandler^  skin_tableRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::skin_tableRowChangeEventHandler^  skin_tableRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::skin_tableRowChangeEventHandler^  skin_tableRowDeleted;
        
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
        property skillFrame::skin_tableRow^  default [::System::Int32 ] {
            skillFrame::skin_tableRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Addskin_tableRow(skillFrame::skin_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillFrame::skin_tableRow^  Addskin_tableRow(skillFrame::player_infoRow^  parentplayer_infoRowByplayer_info_skin_table);
        
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
        skillFrame::skin_tableRow^  Newskin_tableRow();
        
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
        ::System::Void Removeskin_tableRow(skillFrame::skin_tableRow^  row);
        
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
        event skillFrame::skinRowChangeEventHandler^  skinRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::skinRowChangeEventHandler^  skinRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::skinRowChangeEventHandler^  skinRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::skinRowChangeEventHandler^  skinRowDeleted;
        
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
        property skillFrame::skinRow^  default [::System::Int32 ] {
            skillFrame::skinRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddskinRow(skillFrame::skinRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillFrame::skinRow^  AddskinRow(System::String^  name, skillFrame::skin_tableRow^  parentskin_tableRowByskin_table_skin);
        
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
        skillFrame::skinRow^  NewskinRow();
        
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
        ::System::Void RemoveskinRow(skillFrame::skinRow^  row);
        
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
        event skillFrame::object_tableRowChangeEventHandler^  object_tableRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::object_tableRowChangeEventHandler^  object_tableRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::object_tableRowChangeEventHandler^  object_tableRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::object_tableRowChangeEventHandler^  object_tableRowDeleted;
        
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
        property skillFrame::object_tableRow^  default [::System::Int32 ] {
            skillFrame::object_tableRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Addobject_tableRow(skillFrame::object_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillFrame::object_tableRow^  Addobject_tableRow(skillFrame::skillRow^  parentskillRowByskill_object_table);
        
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
        skillFrame::object_tableRow^  Newobject_tableRow();
        
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
        ::System::Void Removeobject_tableRow(skillFrame::object_tableRow^  row);
        
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
        event skillFrame::objectRowChangeEventHandler^  objectRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::objectRowChangeEventHandler^  objectRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::objectRowChangeEventHandler^  objectRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::objectRowChangeEventHandler^  objectRowDeleted;
        
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
        property skillFrame::objectRow^  default [::System::Int32 ] {
            skillFrame::objectRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddobjectRow(skillFrame::objectRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillFrame::objectRow^  AddobjectRow(System::Int32 id, skillFrame::object_tableRow^  parentobject_tableRowByobject_table_object);
        
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
        skillFrame::objectRow^  NewobjectRow();
        
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
        ::System::Void RemoveobjectRow(skillFrame::objectRow^  row);
        
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
        event skillFrame::skill_tableRowChangeEventHandler^  skill_tableRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::skill_tableRowChangeEventHandler^  skill_tableRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::skill_tableRowChangeEventHandler^  skill_tableRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::skill_tableRowChangeEventHandler^  skill_tableRowDeleted;
        
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
        property skillFrame::skill_tableRow^  default [::System::Int32 ] {
            skillFrame::skill_tableRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Addskill_tableRow(skillFrame::skill_tableRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillFrame::skill_tableRow^  Addskill_tableRow(skillFrame::player_infoRow^  parentplayer_infoRowByplayer_info_skill_table);
        
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
        skillFrame::skill_tableRow^  Newskill_tableRow();
        
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
        ::System::Void Removeskill_tableRow(skillFrame::skill_tableRow^  row);
        
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
        event skillFrame::skillRowChangeEventHandler^  skillRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::skillRowChangeEventHandler^  skillRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::skillRowChangeEventHandler^  skillRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::skillRowChangeEventHandler^  skillRowDeleted;
        
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
        property skillFrame::skillRow^  default [::System::Int32 ] {
            skillFrame::skillRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddskillRow(skillFrame::skillRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillFrame::skillRow^  AddskillRow(System::String^  eka, System::String^  as, System::String^  ssse, System::Boolean savable, 
                    skillFrame::skill_tableRow^  parentskill_tableRowByskill_table_skill);
        
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
        skillFrame::skillRow^  NewskillRow();
        
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
        ::System::Void RemoveskillRow(skillFrame::skillRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class player_infoDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnplayer_info_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::player_infoRowChangeEventHandler^  player_infoRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::player_infoRowChangeEventHandler^  player_infoRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::player_infoRowChangeEventHandler^  player_infoRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event skillFrame::player_infoRowChangeEventHandler^  player_infoRowDeleted;
        
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
        property skillFrame::player_infoRow^  default [::System::Int32 ] {
            skillFrame::player_infoRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Addplayer_infoRow(skillFrame::player_infoRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillFrame::player_infoRow^  Addplayer_infoRow();
        
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
        skillFrame::player_infoRow^  Newplayer_infoRow();
        
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
        ::System::Void Removeplayer_infoRow(skillFrame::player_infoRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class rectRow : public ::System::Data::DataRow {
        
        private: skillFrame::rectDataTable^  tablerect;
        
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
        property skillFrame::boxRow^  boxRow {
            skillFrame::boxRow^  get();
            System::Void set(skillFrame::boxRow^  value);
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
///Represents strongly named DataRow class.
///</summary>
    ref class pointRow : public ::System::Data::DataRow {
        
        private: skillFrame::pointDataTable^  tablepoint;
        
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
        property skillFrame::frameRow^  frameRow {
            skillFrame::frameRow^  get();
            System::Void set(skillFrame::frameRow^  value);
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
        
        private: skillFrame::box_tableDataTable^  tablebox_table;
        
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
        property skillFrame::frameRow^  frameRow {
            skillFrame::frameRow^  get();
            System::Void set(skillFrame::frameRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isframe_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setframe_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< skillFrame::boxRow^  >^  GetboxRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class boxRow : public ::System::Data::DataRow {
        
        private: skillFrame::boxDataTable^  tablebox;
        
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
        property skillFrame::box_tableRow^  box_tableRow {
            skillFrame::box_tableRow^  get();
            System::Void set(skillFrame::box_tableRow^  value);
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
        cli::array< skillFrame::rectRow^  >^  GetrectRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class frame_tableRow : public ::System::Data::DataRow {
        
        private: skillFrame::frame_tableDataTable^  tableframe_table;
        
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
        property skillFrame::objectRow^  objectRow {
            skillFrame::objectRow^  get();
            System::Void set(skillFrame::objectRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isobject_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setobject_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< skillFrame::frameRow^  >^  GetframeRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class frameRow : public ::System::Data::DataRow {
        
        private: skillFrame::frameDataTable^  tableframe;
        
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
        property skillFrame::frame_tableRow^  frame_tableRow {
            skillFrame::frame_tableRow^  get();
            System::Void set(skillFrame::frame_tableRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isframe_table_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setframe_table_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< skillFrame::pointRow^  >^  GetpointRows();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< skillFrame::box_tableRow^  >^  Getbox_tableRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class skin_tableRow : public ::System::Data::DataRow {
        
        private: skillFrame::skin_tableDataTable^  tableskin_table;
        
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
        property skillFrame::player_infoRow^  player_infoRow {
            skillFrame::player_infoRow^  get();
            System::Void set(skillFrame::player_infoRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isplayer_info_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setplayer_info_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< skillFrame::skinRow^  >^  GetskinRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class skinRow : public ::System::Data::DataRow {
        
        private: skillFrame::skinDataTable^  tableskin;
        
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
        property skillFrame::skin_tableRow^  skin_tableRow {
            skillFrame::skin_tableRow^  get();
            System::Void set(skillFrame::skin_tableRow^  value);
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
    ref class object_tableRow : public ::System::Data::DataRow {
        
        private: skillFrame::object_tableDataTable^  tableobject_table;
        
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
        property skillFrame::skillRow^  skillRow {
            skillFrame::skillRow^  get();
            System::Void set(skillFrame::skillRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isskill_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setskill_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< skillFrame::objectRow^  >^  GetobjectRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class objectRow : public ::System::Data::DataRow {
        
        private: skillFrame::objectDataTable^  tableobject;
        
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
        property skillFrame::object_tableRow^  object_tableRow {
            skillFrame::object_tableRow^  get();
            System::Void set(skillFrame::object_tableRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isobject_table_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setobject_table_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< skillFrame::frame_tableRow^  >^  Getframe_tableRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class skill_tableRow : public ::System::Data::DataRow {
        
        private: skillFrame::skill_tableDataTable^  tableskill_table;
        
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
        property skillFrame::player_infoRow^  player_infoRow {
            skillFrame::player_infoRow^  get();
            System::Void set(skillFrame::player_infoRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean Isplayer_info_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void Setplayer_info_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< skillFrame::skillRow^  >^  GetskillRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class skillRow : public ::System::Data::DataRow {
        
        private: skillFrame::skillDataTable^  tableskill;
        
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
        property skillFrame::skill_tableRow^  skill_tableRow {
            skillFrame::skill_tableRow^  get();
            System::Void set(skillFrame::skill_tableRow^  value);
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
        cli::array< skillFrame::object_tableRow^  >^  Getobject_tableRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class player_infoRow : public ::System::Data::DataRow {
        
        private: skillFrame::player_infoDataTable^  tableplayer_info;
        
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
        cli::array< skillFrame::skin_tableRow^  >^  Getskin_tableRows();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< skillFrame::skill_tableRow^  >^  Getskill_tableRows();
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class rectRowChangeEvent : public ::System::EventArgs {
        
        private: skillFrame::rectRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        rectRowChangeEvent(skillFrame::rectRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property skillFrame::rectRow^  Row {
            skillFrame::rectRow^  get();
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
        
        private: skillFrame::pointRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        pointRowChangeEvent(skillFrame::pointRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property skillFrame::pointRow^  Row {
            skillFrame::pointRow^  get();
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
        
        private: skillFrame::box_tableRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        box_tableRowChangeEvent(skillFrame::box_tableRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property skillFrame::box_tableRow^  Row {
            skillFrame::box_tableRow^  get();
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
        
        private: skillFrame::boxRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        boxRowChangeEvent(skillFrame::boxRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property skillFrame::boxRow^  Row {
            skillFrame::boxRow^  get();
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
        
        private: skillFrame::frame_tableRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        frame_tableRowChangeEvent(skillFrame::frame_tableRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property skillFrame::frame_tableRow^  Row {
            skillFrame::frame_tableRow^  get();
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
        
        private: skillFrame::frameRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        frameRowChangeEvent(skillFrame::frameRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property skillFrame::frameRow^  Row {
            skillFrame::frameRow^  get();
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
        
        private: skillFrame::skin_tableRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skin_tableRowChangeEvent(skillFrame::skin_tableRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property skillFrame::skin_tableRow^  Row {
            skillFrame::skin_tableRow^  get();
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
        
        private: skillFrame::skinRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skinRowChangeEvent(skillFrame::skinRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property skillFrame::skinRow^  Row {
            skillFrame::skinRow^  get();
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
        
        private: skillFrame::object_tableRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        object_tableRowChangeEvent(skillFrame::object_tableRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property skillFrame::object_tableRow^  Row {
            skillFrame::object_tableRow^  get();
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
        
        private: skillFrame::objectRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        objectRowChangeEvent(skillFrame::objectRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property skillFrame::objectRow^  Row {
            skillFrame::objectRow^  get();
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
        
        private: skillFrame::skill_tableRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skill_tableRowChangeEvent(skillFrame::skill_tableRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property skillFrame::skill_tableRow^  Row {
            skillFrame::skill_tableRow^  get();
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
        
        private: skillFrame::skillRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        skillRowChangeEvent(skillFrame::skillRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property skillFrame::skillRow^  Row {
            skillFrame::skillRow^  get();
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
    ref class player_infoRowChangeEvent : public ::System::EventArgs {
        
        private: skillFrame::player_infoRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        player_infoRowChangeEvent(skillFrame::player_infoRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property skillFrame::player_infoRow^  Row {
            skillFrame::player_infoRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
};


inline skillFrame::skillFrame() {
    this->BeginInit();
    this->InitClass();
    ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &skillFrame::SchemaChanged);
    __super::Tables->CollectionChanged += schemaChangedHandler;
    __super::Relations->CollectionChanged += schemaChangedHandler;
    this->EndInit();
}

inline skillFrame::skillFrame(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataSet(info, context, false) {
    if (this->IsBinarySerialized(info, context) == true) {
        this->InitVars(false);
        ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler1 = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &skillFrame::SchemaChanged);
        this->Tables->CollectionChanged += schemaChangedHandler1;
        this->Relations->CollectionChanged += schemaChangedHandler1;
        return;
    }
    ::System::String^  strSchema = (cli::safe_cast<::System::String^  >(info->GetValue(L"XmlSchema", ::System::String::typeid)));
    if (this->DetermineSchemaSerializationMode(info, context) == ::System::Data::SchemaSerializationMode::IncludeSchema) {
        ::System::Data::DataSet^  ds = (gcnew ::System::Data::DataSet());
        ds->ReadXmlSchema((gcnew ::System::Xml::XmlTextReader((gcnew ::System::IO::StringReader(strSchema)))));
        if (ds->Tables[L"rect"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::rectDataTable(ds->Tables[L"rect"])));
        }
        if (ds->Tables[L"point"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::pointDataTable(ds->Tables[L"point"])));
        }
        if (ds->Tables[L"box_table"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::box_tableDataTable(ds->Tables[L"box_table"])));
        }
        if (ds->Tables[L"box"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::boxDataTable(ds->Tables[L"box"])));
        }
        if (ds->Tables[L"frame_table"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::frame_tableDataTable(ds->Tables[L"frame_table"])));
        }
        if (ds->Tables[L"frame"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::frameDataTable(ds->Tables[L"frame"])));
        }
        if (ds->Tables[L"skin_table"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::skin_tableDataTable(ds->Tables[L"skin_table"])));
        }
        if (ds->Tables[L"skin"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::skinDataTable(ds->Tables[L"skin"])));
        }
        if (ds->Tables[L"object_table"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::object_tableDataTable(ds->Tables[L"object_table"])));
        }
        if (ds->Tables[L"object"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::objectDataTable(ds->Tables[L"object"])));
        }
        if (ds->Tables[L"skill_table"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::skill_tableDataTable(ds->Tables[L"skill_table"])));
        }
        if (ds->Tables[L"skill"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::skillDataTable(ds->Tables[L"skill"])));
        }
        if (ds->Tables[L"player_info"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::player_infoDataTable(ds->Tables[L"player_info"])));
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
    ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &skillFrame::SchemaChanged);
    __super::Tables->CollectionChanged += schemaChangedHandler;
    this->Relations->CollectionChanged += schemaChangedHandler;
}

inline skillFrame::rectDataTable^  skillFrame::rect::get() {
    return this->tablerect;
}

inline skillFrame::pointDataTable^  skillFrame::point::get() {
    return this->tablepoint;
}

inline skillFrame::box_tableDataTable^  skillFrame::box_table::get() {
    return this->tablebox_table;
}

inline skillFrame::boxDataTable^  skillFrame::box::get() {
    return this->tablebox;
}

inline skillFrame::frame_tableDataTable^  skillFrame::frame_table::get() {
    return this->tableframe_table;
}

inline skillFrame::frameDataTable^  skillFrame::frame::get() {
    return this->tableframe;
}

inline skillFrame::skin_tableDataTable^  skillFrame::skin_table::get() {
    return this->tableskin_table;
}

inline skillFrame::skinDataTable^  skillFrame::skin::get() {
    return this->tableskin;
}

inline skillFrame::object_tableDataTable^  skillFrame::object_table::get() {
    return this->tableobject_table;
}

inline skillFrame::objectDataTable^  skillFrame::object::get() {
    return this->tableobject;
}

inline skillFrame::skill_tableDataTable^  skillFrame::skill_table::get() {
    return this->tableskill_table;
}

inline skillFrame::skillDataTable^  skillFrame::skill::get() {
    return this->tableskill;
}

inline skillFrame::player_infoDataTable^  skillFrame::player_info::get() {
    return this->tableplayer_info;
}

inline ::System::Data::SchemaSerializationMode skillFrame::SchemaSerializationMode::get() {
    return this->_schemaSerializationMode;
}
inline System::Void skillFrame::SchemaSerializationMode::set(::System::Data::SchemaSerializationMode value) {
    this->_schemaSerializationMode = __identifier(value);
}

inline ::System::Data::DataTableCollection^  skillFrame::Tables::get() {
    return __super::Tables;
}

inline ::System::Data::DataRelationCollection^  skillFrame::Relations::get() {
    return __super::Relations;
}

inline ::System::Void skillFrame::InitializeDerivedDataSet() {
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline ::System::Data::DataSet^  skillFrame::Clone() {
    skillFrame^  cln = (cli::safe_cast<skillFrame^  >(__super::Clone()));
    cln->InitVars();
    cln->SchemaSerializationMode = this->SchemaSerializationMode;
    return cln;
}

inline ::System::Boolean skillFrame::ShouldSerializeTables() {
    return false;
}

inline ::System::Boolean skillFrame::ShouldSerializeRelations() {
    return false;
}

inline ::System::Void skillFrame::ReadXmlSerializable(::System::Xml::XmlReader^  reader) {
    if (this->DetermineSchemaSerializationMode(reader) == ::System::Data::SchemaSerializationMode::IncludeSchema) {
        this->Reset();
        ::System::Data::DataSet^  ds = (gcnew ::System::Data::DataSet());
        ds->ReadXml(reader);
        if (ds->Tables[L"rect"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::rectDataTable(ds->Tables[L"rect"])));
        }
        if (ds->Tables[L"point"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::pointDataTable(ds->Tables[L"point"])));
        }
        if (ds->Tables[L"box_table"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::box_tableDataTable(ds->Tables[L"box_table"])));
        }
        if (ds->Tables[L"box"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::boxDataTable(ds->Tables[L"box"])));
        }
        if (ds->Tables[L"frame_table"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::frame_tableDataTable(ds->Tables[L"frame_table"])));
        }
        if (ds->Tables[L"frame"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::frameDataTable(ds->Tables[L"frame"])));
        }
        if (ds->Tables[L"skin_table"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::skin_tableDataTable(ds->Tables[L"skin_table"])));
        }
        if (ds->Tables[L"skin"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::skinDataTable(ds->Tables[L"skin"])));
        }
        if (ds->Tables[L"object_table"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::object_tableDataTable(ds->Tables[L"object_table"])));
        }
        if (ds->Tables[L"object"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::objectDataTable(ds->Tables[L"object"])));
        }
        if (ds->Tables[L"skill_table"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::skill_tableDataTable(ds->Tables[L"skill_table"])));
        }
        if (ds->Tables[L"skill"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::skillDataTable(ds->Tables[L"skill"])));
        }
        if (ds->Tables[L"player_info"] != nullptr) {
            __super::Tables->Add((gcnew skillFrame::player_infoDataTable(ds->Tables[L"player_info"])));
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

inline ::System::Xml::Schema::XmlSchema^  skillFrame::GetSchemaSerializable() {
    ::System::IO::MemoryStream^  stream = (gcnew ::System::IO::MemoryStream());
    this->WriteXmlSchema((gcnew ::System::Xml::XmlTextWriter(stream, nullptr)));
    stream->Position = 0;
    return ::System::Xml::Schema::XmlSchema::Read((gcnew ::System::Xml::XmlTextReader(stream)), nullptr);
}

inline ::System::Void skillFrame::InitVars() {
    this->InitVars(true);
}

inline ::System::Void skillFrame::InitVars(::System::Boolean initTable) {
    this->tablerect = (cli::safe_cast<skillFrame::rectDataTable^  >(__super::Tables[L"rect"]));
    if (initTable == true) {
        if (this->tablerect != nullptr) {
            this->tablerect->InitVars();
        }
    }
    this->tablepoint = (cli::safe_cast<skillFrame::pointDataTable^  >(__super::Tables[L"point"]));
    if (initTable == true) {
        if (this->tablepoint != nullptr) {
            this->tablepoint->InitVars();
        }
    }
    this->tablebox_table = (cli::safe_cast<skillFrame::box_tableDataTable^  >(__super::Tables[L"box_table"]));
    if (initTable == true) {
        if (this->tablebox_table != nullptr) {
            this->tablebox_table->InitVars();
        }
    }
    this->tablebox = (cli::safe_cast<skillFrame::boxDataTable^  >(__super::Tables[L"box"]));
    if (initTable == true) {
        if (this->tablebox != nullptr) {
            this->tablebox->InitVars();
        }
    }
    this->tableframe_table = (cli::safe_cast<skillFrame::frame_tableDataTable^  >(__super::Tables[L"frame_table"]));
    if (initTable == true) {
        if (this->tableframe_table != nullptr) {
            this->tableframe_table->InitVars();
        }
    }
    this->tableframe = (cli::safe_cast<skillFrame::frameDataTable^  >(__super::Tables[L"frame"]));
    if (initTable == true) {
        if (this->tableframe != nullptr) {
            this->tableframe->InitVars();
        }
    }
    this->tableskin_table = (cli::safe_cast<skillFrame::skin_tableDataTable^  >(__super::Tables[L"skin_table"]));
    if (initTable == true) {
        if (this->tableskin_table != nullptr) {
            this->tableskin_table->InitVars();
        }
    }
    this->tableskin = (cli::safe_cast<skillFrame::skinDataTable^  >(__super::Tables[L"skin"]));
    if (initTable == true) {
        if (this->tableskin != nullptr) {
            this->tableskin->InitVars();
        }
    }
    this->tableobject_table = (cli::safe_cast<skillFrame::object_tableDataTable^  >(__super::Tables[L"object_table"]));
    if (initTable == true) {
        if (this->tableobject_table != nullptr) {
            this->tableobject_table->InitVars();
        }
    }
    this->tableobject = (cli::safe_cast<skillFrame::objectDataTable^  >(__super::Tables[L"object"]));
    if (initTable == true) {
        if (this->tableobject != nullptr) {
            this->tableobject->InitVars();
        }
    }
    this->tableskill_table = (cli::safe_cast<skillFrame::skill_tableDataTable^  >(__super::Tables[L"skill_table"]));
    if (initTable == true) {
        if (this->tableskill_table != nullptr) {
            this->tableskill_table->InitVars();
        }
    }
    this->tableskill = (cli::safe_cast<skillFrame::skillDataTable^  >(__super::Tables[L"skill"]));
    if (initTable == true) {
        if (this->tableskill != nullptr) {
            this->tableskill->InitVars();
        }
    }
    this->tableplayer_info = (cli::safe_cast<skillFrame::player_infoDataTable^  >(__super::Tables[L"player_info"]));
    if (initTable == true) {
        if (this->tableplayer_info != nullptr) {
            this->tableplayer_info->InitVars();
        }
    }
    this->relationbox_rect = this->Relations[L"box_rect"];
    this->relationframe_point = this->Relations[L"frame_point"];
    this->relationframe_box_table = this->Relations[L"frame_box_table"];
    this->relationbox_table_box = this->Relations[L"box_table_box"];
    this->relationobject_frame_table = this->Relations[L"object_frame_table"];
    this->relationframe_table_frame = this->Relations[L"frame_table_frame"];
    this->relationplayer_info_skin_table = this->Relations[L"player_info_skin_table"];
    this->relationskin_table_skin = this->Relations[L"skin_table_skin"];
    this->relationskill_object_table = this->Relations[L"skill_object_table"];
    this->relationobject_table_object = this->Relations[L"object_table_object"];
    this->relationplayer_info_skill_table = this->Relations[L"player_info_skill_table"];
    this->relationskill_table_skill = this->Relations[L"skill_table_skill"];
}

inline ::System::Void skillFrame::InitClass() {
    this->DataSetName = L"skillFrame";
    this->Prefix = L"";
    this->Namespace = L"http://tkmgame.com/shark/playerFrame.xsd";
    this->Locale = (gcnew ::System::Globalization::CultureInfo(L""));
    this->EnforceConstraints = true;
    this->SchemaSerializationMode = ::System::Data::SchemaSerializationMode::IncludeSchema;
    this->tablerect = (gcnew skillFrame::rectDataTable());
    __super::Tables->Add(this->tablerect);
    this->tablepoint = (gcnew skillFrame::pointDataTable());
    __super::Tables->Add(this->tablepoint);
    this->tablebox_table = (gcnew skillFrame::box_tableDataTable());
    __super::Tables->Add(this->tablebox_table);
    this->tablebox = (gcnew skillFrame::boxDataTable());
    __super::Tables->Add(this->tablebox);
    this->tableframe_table = (gcnew skillFrame::frame_tableDataTable());
    __super::Tables->Add(this->tableframe_table);
    this->tableframe = (gcnew skillFrame::frameDataTable());
    __super::Tables->Add(this->tableframe);
    this->tableskin_table = (gcnew skillFrame::skin_tableDataTable());
    __super::Tables->Add(this->tableskin_table);
    this->tableskin = (gcnew skillFrame::skinDataTable());
    __super::Tables->Add(this->tableskin);
    this->tableobject_table = (gcnew skillFrame::object_tableDataTable());
    __super::Tables->Add(this->tableobject_table);
    this->tableobject = (gcnew skillFrame::objectDataTable());
    __super::Tables->Add(this->tableobject);
    this->tableskill_table = (gcnew skillFrame::skill_tableDataTable());
    __super::Tables->Add(this->tableskill_table);
    this->tableskill = (gcnew skillFrame::skillDataTable());
    __super::Tables->Add(this->tableskill);
    this->tableplayer_info = (gcnew skillFrame::player_infoDataTable());
    __super::Tables->Add(this->tableplayer_info);
    ::System::Data::ForeignKeyConstraint^  fkc;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"box_rect", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablebox->box_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablerect->box_IdColumn}));
    this->tablerect->Constraints->Add(fkc);
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
    this->relationbox_rect = (gcnew ::System::Data::DataRelation(L"box_rect", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablebox->box_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablerect->box_IdColumn}, false));
    this->relationbox_rect->Nested = true;
    this->Relations->Add(this->relationbox_rect);
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
    this->relationobject_frame_table = (gcnew ::System::Data::DataRelation(L"object_frame_table", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableobject->object_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableframe_table->object_IdColumn}, false));
    this->relationobject_frame_table->Nested = true;
    this->Relations->Add(this->relationobject_frame_table);
    this->relationframe_table_frame = (gcnew ::System::Data::DataRelation(L"frame_table_frame", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableframe_table->frame_table_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableframe->frame_table_IdColumn}, false));
    this->relationframe_table_frame->Nested = true;
    this->Relations->Add(this->relationframe_table_frame);
    this->relationplayer_info_skin_table = (gcnew ::System::Data::DataRelation(L"player_info_skin_table", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableplayer_info->player_info_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskin_table->player_info_IdColumn}, false));
    this->relationplayer_info_skin_table->Nested = true;
    this->Relations->Add(this->relationplayer_info_skin_table);
    this->relationskin_table_skin = (gcnew ::System::Data::DataRelation(L"skin_table_skin", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskin_table->skin_table_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskin->skin_table_IdColumn}, false));
    this->relationskin_table_skin->Nested = true;
    this->Relations->Add(this->relationskin_table_skin);
    this->relationskill_object_table = (gcnew ::System::Data::DataRelation(L"skill_object_table", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskill->skill_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableobject_table->skill_IdColumn}, false));
    this->relationskill_object_table->Nested = true;
    this->Relations->Add(this->relationskill_object_table);
    this->relationobject_table_object = (gcnew ::System::Data::DataRelation(L"object_table_object", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableobject_table->object_table_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableobject->object_table_IdColumn}, false));
    this->relationobject_table_object->Nested = true;
    this->Relations->Add(this->relationobject_table_object);
    this->relationplayer_info_skill_table = (gcnew ::System::Data::DataRelation(L"player_info_skill_table", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableplayer_info->player_info_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskill_table->player_info_IdColumn}, false));
    this->relationplayer_info_skill_table->Nested = true;
    this->Relations->Add(this->relationplayer_info_skill_table);
    this->relationskill_table_skill = (gcnew ::System::Data::DataRelation(L"skill_table_skill", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskill_table->skill_table_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableskill->skill_table_IdColumn}, false));
    this->relationskill_table_skill->Nested = true;
    this->Relations->Add(this->relationskill_table_skill);
}

inline ::System::Boolean skillFrame::ShouldSerializerect() {
    return false;
}

inline ::System::Boolean skillFrame::ShouldSerializepoint() {
    return false;
}

inline ::System::Boolean skillFrame::ShouldSerializebox_table() {
    return false;
}

inline ::System::Boolean skillFrame::ShouldSerializebox() {
    return false;
}

inline ::System::Boolean skillFrame::ShouldSerializeframe_table() {
    return false;
}

inline ::System::Boolean skillFrame::ShouldSerializeframe() {
    return false;
}

inline ::System::Boolean skillFrame::ShouldSerializeskin_table() {
    return false;
}

inline ::System::Boolean skillFrame::ShouldSerializeskin() {
    return false;
}

inline ::System::Boolean skillFrame::ShouldSerializeobject_table() {
    return false;
}

inline ::System::Boolean skillFrame::ShouldSerializeobject() {
    return false;
}

inline ::System::Boolean skillFrame::ShouldSerializeskill_table() {
    return false;
}

inline ::System::Boolean skillFrame::ShouldSerializeskill() {
    return false;
}

inline ::System::Boolean skillFrame::ShouldSerializeplayer_info() {
    return false;
}

inline ::System::Void skillFrame::SchemaChanged(::System::Object^  sender, ::System::ComponentModel::CollectionChangeEventArgs^  e) {
    if (e->Action == ::System::ComponentModel::CollectionChangeAction::Remove) {
        this->InitVars();
    }
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  skillFrame::GetTypedDataSetSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    skillFrame^  ds = (gcnew skillFrame());
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


inline skillFrame::rectDataTable::rectDataTable() {
    this->TableName = L"rect";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline skillFrame::rectDataTable::rectDataTable(::System::Data::DataTable^  table) {
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

inline skillFrame::rectDataTable::rectDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  skillFrame::rectDataTable::tColumn::get() {
    return this->columnt;
}

inline ::System::Data::DataColumn^  skillFrame::rectDataTable::lColumn::get() {
    return this->columnl;
}

inline ::System::Data::DataColumn^  skillFrame::rectDataTable::bColumn::get() {
    return this->columnb;
}

inline ::System::Data::DataColumn^  skillFrame::rectDataTable::rColumn::get() {
    return this->columnr;
}

inline ::System::Data::DataColumn^  skillFrame::rectDataTable::box_IdColumn::get() {
    return this->columnbox_Id;
}

inline ::System::Int32 skillFrame::rectDataTable::Count::get() {
    return this->Rows->Count;
}

inline skillFrame::rectRow^  skillFrame::rectDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<skillFrame::rectRow^  >(this->Rows[index]));
}

inline ::System::Void skillFrame::rectDataTable::AddrectRow(skillFrame::rectRow^  row) {
    this->Rows->Add(row);
}

inline skillFrame::rectRow^  skillFrame::rectDataTable::AddrectRow(System::Single t, System::Single l, System::Single b, 
            System::Single r, skillFrame::boxRow^  parentboxRowBybox_rect) {
    skillFrame::rectRow^  rowrectRow = (cli::safe_cast<skillFrame::rectRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(5) {t, l, b, r, nullptr};
    if (parentboxRowBybox_rect != nullptr) {
        columnValuesArray[4] = parentboxRowBybox_rect[1];
    }
    rowrectRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowrectRow);
    return rowrectRow;
}

inline ::System::Collections::IEnumerator^  skillFrame::rectDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  skillFrame::rectDataTable::Clone() {
    skillFrame::rectDataTable^  cln = (cli::safe_cast<skillFrame::rectDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  skillFrame::rectDataTable::CreateInstance() {
    return (gcnew skillFrame::rectDataTable());
}

inline ::System::Void skillFrame::rectDataTable::InitVars() {
    this->columnt = __super::Columns[L"t"];
    this->columnl = __super::Columns[L"l"];
    this->columnb = __super::Columns[L"b"];
    this->columnr = __super::Columns[L"r"];
    this->columnbox_Id = __super::Columns[L"box_Id"];
}

inline ::System::Void skillFrame::rectDataTable::InitClass() {
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

inline skillFrame::rectRow^  skillFrame::rectDataTable::NewrectRow() {
    return (cli::safe_cast<skillFrame::rectRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  skillFrame::rectDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew skillFrame::rectRow(builder));
}

inline ::System::Type^  skillFrame::rectDataTable::GetRowType() {
    return skillFrame::rectRow::typeid;
}

inline ::System::Void skillFrame::rectDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->rectRowChanged(this, (gcnew skillFrame::rectRowChangeEvent((cli::safe_cast<skillFrame::rectRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void skillFrame::rectDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->rectRowChanging(this, (gcnew skillFrame::rectRowChangeEvent((cli::safe_cast<skillFrame::rectRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void skillFrame::rectDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->rectRowDeleted(this, (gcnew skillFrame::rectRowChangeEvent((cli::safe_cast<skillFrame::rectRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void skillFrame::rectDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->rectRowDeleting(this, (gcnew skillFrame::rectRowChangeEvent((cli::safe_cast<skillFrame::rectRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void skillFrame::rectDataTable::RemoverectRow(skillFrame::rectRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  skillFrame::rectDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    skillFrame^  ds = (gcnew skillFrame());
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


inline skillFrame::pointDataTable::pointDataTable() {
    this->TableName = L"point";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline skillFrame::pointDataTable::pointDataTable(::System::Data::DataTable^  table) {
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

inline skillFrame::pointDataTable::pointDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  skillFrame::pointDataTable::xColumn::get() {
    return this->columnx;
}

inline ::System::Data::DataColumn^  skillFrame::pointDataTable::yColumn::get() {
    return this->columny;
}

inline ::System::Data::DataColumn^  skillFrame::pointDataTable::frame_IdColumn::get() {
    return this->columnframe_Id;
}

inline ::System::Int32 skillFrame::pointDataTable::Count::get() {
    return this->Rows->Count;
}

inline skillFrame::pointRow^  skillFrame::pointDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<skillFrame::pointRow^  >(this->Rows[index]));
}

inline ::System::Void skillFrame::pointDataTable::AddpointRow(skillFrame::pointRow^  row) {
    this->Rows->Add(row);
}

inline skillFrame::pointRow^  skillFrame::pointDataTable::AddpointRow(System::Single x, System::Single y, skillFrame::frameRow^  parentframeRowByframe_point) {
    skillFrame::pointRow^  rowpointRow = (cli::safe_cast<skillFrame::pointRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(3) {x, y, nullptr};
    if (parentframeRowByframe_point != nullptr) {
        columnValuesArray[2] = parentframeRowByframe_point[1];
    }
    rowpointRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowpointRow);
    return rowpointRow;
}

inline ::System::Collections::IEnumerator^  skillFrame::pointDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  skillFrame::pointDataTable::Clone() {
    skillFrame::pointDataTable^  cln = (cli::safe_cast<skillFrame::pointDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  skillFrame::pointDataTable::CreateInstance() {
    return (gcnew skillFrame::pointDataTable());
}

inline ::System::Void skillFrame::pointDataTable::InitVars() {
    this->columnx = __super::Columns[L"x"];
    this->columny = __super::Columns[L"y"];
    this->columnframe_Id = __super::Columns[L"frame_Id"];
}

inline ::System::Void skillFrame::pointDataTable::InitClass() {
    this->columnx = (gcnew ::System::Data::DataColumn(L"x", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columnx);
    this->columny = (gcnew ::System::Data::DataColumn(L"y", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columny);
    this->columnframe_Id = (gcnew ::System::Data::DataColumn(L"frame_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnframe_Id);
    this->columnx->Namespace = L"";
    this->columny->Namespace = L"";
}

inline skillFrame::pointRow^  skillFrame::pointDataTable::NewpointRow() {
    return (cli::safe_cast<skillFrame::pointRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  skillFrame::pointDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew skillFrame::pointRow(builder));
}

inline ::System::Type^  skillFrame::pointDataTable::GetRowType() {
    return skillFrame::pointRow::typeid;
}

inline ::System::Void skillFrame::pointDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->pointRowChanged(this, (gcnew skillFrame::pointRowChangeEvent((cli::safe_cast<skillFrame::pointRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::pointDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->pointRowChanging(this, (gcnew skillFrame::pointRowChangeEvent((cli::safe_cast<skillFrame::pointRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::pointDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->pointRowDeleted(this, (gcnew skillFrame::pointRowChangeEvent((cli::safe_cast<skillFrame::pointRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::pointDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->pointRowDeleting(this, (gcnew skillFrame::pointRowChangeEvent((cli::safe_cast<skillFrame::pointRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::pointDataTable::RemovepointRow(skillFrame::pointRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  skillFrame::pointDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    skillFrame^  ds = (gcnew skillFrame());
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


inline skillFrame::box_tableDataTable::box_tableDataTable() {
    this->TableName = L"box_table";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline skillFrame::box_tableDataTable::box_tableDataTable(::System::Data::DataTable^  table) {
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

inline skillFrame::box_tableDataTable::box_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  skillFrame::box_tableDataTable::box_table_IdColumn::get() {
    return this->columnbox_table_Id;
}

inline ::System::Data::DataColumn^  skillFrame::box_tableDataTable::frame_IdColumn::get() {
    return this->columnframe_Id;
}

inline ::System::Int32 skillFrame::box_tableDataTable::Count::get() {
    return this->Rows->Count;
}

inline skillFrame::box_tableRow^  skillFrame::box_tableDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<skillFrame::box_tableRow^  >(this->Rows[index]));
}

inline ::System::Void skillFrame::box_tableDataTable::Addbox_tableRow(skillFrame::box_tableRow^  row) {
    this->Rows->Add(row);
}

inline skillFrame::box_tableRow^  skillFrame::box_tableDataTable::Addbox_tableRow(skillFrame::frameRow^  parentframeRowByframe_box_table) {
    skillFrame::box_tableRow^  rowbox_tableRow = (cli::safe_cast<skillFrame::box_tableRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {nullptr, nullptr};
    if (parentframeRowByframe_box_table != nullptr) {
        columnValuesArray[1] = parentframeRowByframe_box_table[1];
    }
    rowbox_tableRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowbox_tableRow);
    return rowbox_tableRow;
}

inline ::System::Collections::IEnumerator^  skillFrame::box_tableDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  skillFrame::box_tableDataTable::Clone() {
    skillFrame::box_tableDataTable^  cln = (cli::safe_cast<skillFrame::box_tableDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  skillFrame::box_tableDataTable::CreateInstance() {
    return (gcnew skillFrame::box_tableDataTable());
}

inline ::System::Void skillFrame::box_tableDataTable::InitVars() {
    this->columnbox_table_Id = __super::Columns[L"box_table_Id"];
    this->columnframe_Id = __super::Columns[L"frame_Id"];
}

inline ::System::Void skillFrame::box_tableDataTable::InitClass() {
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

inline skillFrame::box_tableRow^  skillFrame::box_tableDataTable::Newbox_tableRow() {
    return (cli::safe_cast<skillFrame::box_tableRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  skillFrame::box_tableDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew skillFrame::box_tableRow(builder));
}

inline ::System::Type^  skillFrame::box_tableDataTable::GetRowType() {
    return skillFrame::box_tableRow::typeid;
}

inline ::System::Void skillFrame::box_tableDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->box_tableRowChanged(this, (gcnew skillFrame::box_tableRowChangeEvent((cli::safe_cast<skillFrame::box_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::box_tableDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->box_tableRowChanging(this, (gcnew skillFrame::box_tableRowChangeEvent((cli::safe_cast<skillFrame::box_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::box_tableDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->box_tableRowDeleted(this, (gcnew skillFrame::box_tableRowChangeEvent((cli::safe_cast<skillFrame::box_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::box_tableDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->box_tableRowDeleting(this, (gcnew skillFrame::box_tableRowChangeEvent((cli::safe_cast<skillFrame::box_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::box_tableDataTable::Removebox_tableRow(skillFrame::box_tableRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  skillFrame::box_tableDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    skillFrame^  ds = (gcnew skillFrame());
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


inline skillFrame::boxDataTable::boxDataTable() {
    this->TableName = L"box";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline skillFrame::boxDataTable::boxDataTable(::System::Data::DataTable^  table) {
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

inline skillFrame::boxDataTable::boxDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  skillFrame::boxDataTable::typeColumn::get() {
    return this->columntype;
}

inline ::System::Data::DataColumn^  skillFrame::boxDataTable::box_IdColumn::get() {
    return this->columnbox_Id;
}

inline ::System::Data::DataColumn^  skillFrame::boxDataTable::box_table_IdColumn::get() {
    return this->columnbox_table_Id;
}

inline ::System::Int32 skillFrame::boxDataTable::Count::get() {
    return this->Rows->Count;
}

inline skillFrame::boxRow^  skillFrame::boxDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<skillFrame::boxRow^  >(this->Rows[index]));
}

inline ::System::Void skillFrame::boxDataTable::AddboxRow(skillFrame::boxRow^  row) {
    this->Rows->Add(row);
}

inline skillFrame::boxRow^  skillFrame::boxDataTable::AddboxRow(System::Int32 type, skillFrame::box_tableRow^  parentbox_tableRowBybox_table_box) {
    skillFrame::boxRow^  rowboxRow = (cli::safe_cast<skillFrame::boxRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(3) {type, nullptr, nullptr};
    if (parentbox_tableRowBybox_table_box != nullptr) {
        columnValuesArray[2] = parentbox_tableRowBybox_table_box[0];
    }
    rowboxRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowboxRow);
    return rowboxRow;
}

inline ::System::Collections::IEnumerator^  skillFrame::boxDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  skillFrame::boxDataTable::Clone() {
    skillFrame::boxDataTable^  cln = (cli::safe_cast<skillFrame::boxDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  skillFrame::boxDataTable::CreateInstance() {
    return (gcnew skillFrame::boxDataTable());
}

inline ::System::Void skillFrame::boxDataTable::InitVars() {
    this->columntype = __super::Columns[L"type"];
    this->columnbox_Id = __super::Columns[L"box_Id"];
    this->columnbox_table_Id = __super::Columns[L"box_table_Id"];
}

inline ::System::Void skillFrame::boxDataTable::InitClass() {
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

inline skillFrame::boxRow^  skillFrame::boxDataTable::NewboxRow() {
    return (cli::safe_cast<skillFrame::boxRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  skillFrame::boxDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew skillFrame::boxRow(builder));
}

inline ::System::Type^  skillFrame::boxDataTable::GetRowType() {
    return skillFrame::boxRow::typeid;
}

inline ::System::Void skillFrame::boxDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->boxRowChanged(this, (gcnew skillFrame::boxRowChangeEvent((cli::safe_cast<skillFrame::boxRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void skillFrame::boxDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->boxRowChanging(this, (gcnew skillFrame::boxRowChangeEvent((cli::safe_cast<skillFrame::boxRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void skillFrame::boxDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->boxRowDeleted(this, (gcnew skillFrame::boxRowChangeEvent((cli::safe_cast<skillFrame::boxRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void skillFrame::boxDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->boxRowDeleting(this, (gcnew skillFrame::boxRowChangeEvent((cli::safe_cast<skillFrame::boxRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void skillFrame::boxDataTable::RemoveboxRow(skillFrame::boxRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  skillFrame::boxDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    skillFrame^  ds = (gcnew skillFrame());
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


inline skillFrame::frame_tableDataTable::frame_tableDataTable() {
    this->TableName = L"frame_table";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline skillFrame::frame_tableDataTable::frame_tableDataTable(::System::Data::DataTable^  table) {
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

inline skillFrame::frame_tableDataTable::frame_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, 
            ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  skillFrame::frame_tableDataTable::frame_table_IdColumn::get() {
    return this->columnframe_table_Id;
}

inline ::System::Data::DataColumn^  skillFrame::frame_tableDataTable::object_IdColumn::get() {
    return this->columnobject_Id;
}

inline ::System::Int32 skillFrame::frame_tableDataTable::Count::get() {
    return this->Rows->Count;
}

inline skillFrame::frame_tableRow^  skillFrame::frame_tableDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<skillFrame::frame_tableRow^  >(this->Rows[index]));
}

inline ::System::Void skillFrame::frame_tableDataTable::Addframe_tableRow(skillFrame::frame_tableRow^  row) {
    this->Rows->Add(row);
}

inline skillFrame::frame_tableRow^  skillFrame::frame_tableDataTable::Addframe_tableRow(skillFrame::objectRow^  parentobjectRowByobject_frame_table) {
    skillFrame::frame_tableRow^  rowframe_tableRow = (cli::safe_cast<skillFrame::frame_tableRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {nullptr, nullptr};
    if (parentobjectRowByobject_frame_table != nullptr) {
        columnValuesArray[1] = parentobjectRowByobject_frame_table[1];
    }
    rowframe_tableRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowframe_tableRow);
    return rowframe_tableRow;
}

inline ::System::Collections::IEnumerator^  skillFrame::frame_tableDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  skillFrame::frame_tableDataTable::Clone() {
    skillFrame::frame_tableDataTable^  cln = (cli::safe_cast<skillFrame::frame_tableDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  skillFrame::frame_tableDataTable::CreateInstance() {
    return (gcnew skillFrame::frame_tableDataTable());
}

inline ::System::Void skillFrame::frame_tableDataTable::InitVars() {
    this->columnframe_table_Id = __super::Columns[L"frame_table_Id"];
    this->columnobject_Id = __super::Columns[L"object_Id"];
}

inline ::System::Void skillFrame::frame_tableDataTable::InitClass() {
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

inline skillFrame::frame_tableRow^  skillFrame::frame_tableDataTable::Newframe_tableRow() {
    return (cli::safe_cast<skillFrame::frame_tableRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  skillFrame::frame_tableDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew skillFrame::frame_tableRow(builder));
}

inline ::System::Type^  skillFrame::frame_tableDataTable::GetRowType() {
    return skillFrame::frame_tableRow::typeid;
}

inline ::System::Void skillFrame::frame_tableDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->frame_tableRowChanged(this, (gcnew skillFrame::frame_tableRowChangeEvent((cli::safe_cast<skillFrame::frame_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::frame_tableDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->frame_tableRowChanging(this, (gcnew skillFrame::frame_tableRowChangeEvent((cli::safe_cast<skillFrame::frame_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::frame_tableDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->frame_tableRowDeleted(this, (gcnew skillFrame::frame_tableRowChangeEvent((cli::safe_cast<skillFrame::frame_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::frame_tableDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->frame_tableRowDeleting(this, (gcnew skillFrame::frame_tableRowChangeEvent((cli::safe_cast<skillFrame::frame_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::frame_tableDataTable::Removeframe_tableRow(skillFrame::frame_tableRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  skillFrame::frame_tableDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    skillFrame^  ds = (gcnew skillFrame());
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


inline skillFrame::frameDataTable::frameDataTable() {
    this->TableName = L"frame";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline skillFrame::frameDataTable::frameDataTable(::System::Data::DataTable^  table) {
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

inline skillFrame::frameDataTable::frameDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  skillFrame::frameDataTable::idColumn::get() {
    return this->columnid;
}

inline ::System::Data::DataColumn^  skillFrame::frameDataTable::frame_IdColumn::get() {
    return this->columnframe_Id;
}

inline ::System::Data::DataColumn^  skillFrame::frameDataTable::frame_table_IdColumn::get() {
    return this->columnframe_table_Id;
}

inline ::System::Int32 skillFrame::frameDataTable::Count::get() {
    return this->Rows->Count;
}

inline skillFrame::frameRow^  skillFrame::frameDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<skillFrame::frameRow^  >(this->Rows[index]));
}

inline ::System::Void skillFrame::frameDataTable::AddframeRow(skillFrame::frameRow^  row) {
    this->Rows->Add(row);
}

inline skillFrame::frameRow^  skillFrame::frameDataTable::AddframeRow(System::Int32 id, skillFrame::frame_tableRow^  parentframe_tableRowByframe_table_frame) {
    skillFrame::frameRow^  rowframeRow = (cli::safe_cast<skillFrame::frameRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(3) {id, nullptr, nullptr};
    if (parentframe_tableRowByframe_table_frame != nullptr) {
        columnValuesArray[2] = parentframe_tableRowByframe_table_frame[0];
    }
    rowframeRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowframeRow);
    return rowframeRow;
}

inline ::System::Collections::IEnumerator^  skillFrame::frameDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  skillFrame::frameDataTable::Clone() {
    skillFrame::frameDataTable^  cln = (cli::safe_cast<skillFrame::frameDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  skillFrame::frameDataTable::CreateInstance() {
    return (gcnew skillFrame::frameDataTable());
}

inline ::System::Void skillFrame::frameDataTable::InitVars() {
    this->columnid = __super::Columns[L"id"];
    this->columnframe_Id = __super::Columns[L"frame_Id"];
    this->columnframe_table_Id = __super::Columns[L"frame_table_Id"];
}

inline ::System::Void skillFrame::frameDataTable::InitClass() {
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

inline skillFrame::frameRow^  skillFrame::frameDataTable::NewframeRow() {
    return (cli::safe_cast<skillFrame::frameRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  skillFrame::frameDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew skillFrame::frameRow(builder));
}

inline ::System::Type^  skillFrame::frameDataTable::GetRowType() {
    return skillFrame::frameRow::typeid;
}

inline ::System::Void skillFrame::frameDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->frameRowChanged(this, (gcnew skillFrame::frameRowChangeEvent((cli::safe_cast<skillFrame::frameRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::frameDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->frameRowChanging(this, (gcnew skillFrame::frameRowChangeEvent((cli::safe_cast<skillFrame::frameRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::frameDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->frameRowDeleted(this, (gcnew skillFrame::frameRowChangeEvent((cli::safe_cast<skillFrame::frameRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::frameDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->frameRowDeleting(this, (gcnew skillFrame::frameRowChangeEvent((cli::safe_cast<skillFrame::frameRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::frameDataTable::RemoveframeRow(skillFrame::frameRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  skillFrame::frameDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    skillFrame^  ds = (gcnew skillFrame());
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


inline skillFrame::skin_tableDataTable::skin_tableDataTable() {
    this->TableName = L"skin_table";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline skillFrame::skin_tableDataTable::skin_tableDataTable(::System::Data::DataTable^  table) {
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

inline skillFrame::skin_tableDataTable::skin_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  skillFrame::skin_tableDataTable::skin_table_IdColumn::get() {
    return this->columnskin_table_Id;
}

inline ::System::Data::DataColumn^  skillFrame::skin_tableDataTable::player_info_IdColumn::get() {
    return this->columnplayer_info_Id;
}

inline ::System::Int32 skillFrame::skin_tableDataTable::Count::get() {
    return this->Rows->Count;
}

inline skillFrame::skin_tableRow^  skillFrame::skin_tableDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<skillFrame::skin_tableRow^  >(this->Rows[index]));
}

inline ::System::Void skillFrame::skin_tableDataTable::Addskin_tableRow(skillFrame::skin_tableRow^  row) {
    this->Rows->Add(row);
}

inline skillFrame::skin_tableRow^  skillFrame::skin_tableDataTable::Addskin_tableRow(skillFrame::player_infoRow^  parentplayer_infoRowByplayer_info_skin_table) {
    skillFrame::skin_tableRow^  rowskin_tableRow = (cli::safe_cast<skillFrame::skin_tableRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {nullptr, nullptr};
    if (parentplayer_infoRowByplayer_info_skin_table != nullptr) {
        columnValuesArray[1] = parentplayer_infoRowByplayer_info_skin_table[0];
    }
    rowskin_tableRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowskin_tableRow);
    return rowskin_tableRow;
}

inline ::System::Collections::IEnumerator^  skillFrame::skin_tableDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  skillFrame::skin_tableDataTable::Clone() {
    skillFrame::skin_tableDataTable^  cln = (cli::safe_cast<skillFrame::skin_tableDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  skillFrame::skin_tableDataTable::CreateInstance() {
    return (gcnew skillFrame::skin_tableDataTable());
}

inline ::System::Void skillFrame::skin_tableDataTable::InitVars() {
    this->columnskin_table_Id = __super::Columns[L"skin_table_Id"];
    this->columnplayer_info_Id = __super::Columns[L"player_info_Id"];
}

inline ::System::Void skillFrame::skin_tableDataTable::InitClass() {
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

inline skillFrame::skin_tableRow^  skillFrame::skin_tableDataTable::Newskin_tableRow() {
    return (cli::safe_cast<skillFrame::skin_tableRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  skillFrame::skin_tableDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew skillFrame::skin_tableRow(builder));
}

inline ::System::Type^  skillFrame::skin_tableDataTable::GetRowType() {
    return skillFrame::skin_tableRow::typeid;
}

inline ::System::Void skillFrame::skin_tableDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->skin_tableRowChanged(this, (gcnew skillFrame::skin_tableRowChangeEvent((cli::safe_cast<skillFrame::skin_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::skin_tableDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->skin_tableRowChanging(this, (gcnew skillFrame::skin_tableRowChangeEvent((cli::safe_cast<skillFrame::skin_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::skin_tableDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->skin_tableRowDeleted(this, (gcnew skillFrame::skin_tableRowChangeEvent((cli::safe_cast<skillFrame::skin_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::skin_tableDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->skin_tableRowDeleting(this, (gcnew skillFrame::skin_tableRowChangeEvent((cli::safe_cast<skillFrame::skin_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::skin_tableDataTable::Removeskin_tableRow(skillFrame::skin_tableRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  skillFrame::skin_tableDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    skillFrame^  ds = (gcnew skillFrame());
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


inline skillFrame::skinDataTable::skinDataTable() {
    this->TableName = L"skin";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline skillFrame::skinDataTable::skinDataTable(::System::Data::DataTable^  table) {
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

inline skillFrame::skinDataTable::skinDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  skillFrame::skinDataTable::nameColumn::get() {
    return this->columnname;
}

inline ::System::Data::DataColumn^  skillFrame::skinDataTable::skin_table_IdColumn::get() {
    return this->columnskin_table_Id;
}

inline ::System::Int32 skillFrame::skinDataTable::Count::get() {
    return this->Rows->Count;
}

inline skillFrame::skinRow^  skillFrame::skinDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<skillFrame::skinRow^  >(this->Rows[index]));
}

inline ::System::Void skillFrame::skinDataTable::AddskinRow(skillFrame::skinRow^  row) {
    this->Rows->Add(row);
}

inline skillFrame::skinRow^  skillFrame::skinDataTable::AddskinRow(System::String^  name, skillFrame::skin_tableRow^  parentskin_tableRowByskin_table_skin) {
    skillFrame::skinRow^  rowskinRow = (cli::safe_cast<skillFrame::skinRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {name, nullptr};
    if (parentskin_tableRowByskin_table_skin != nullptr) {
        columnValuesArray[1] = parentskin_tableRowByskin_table_skin[0];
    }
    rowskinRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowskinRow);
    return rowskinRow;
}

inline ::System::Collections::IEnumerator^  skillFrame::skinDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  skillFrame::skinDataTable::Clone() {
    skillFrame::skinDataTable^  cln = (cli::safe_cast<skillFrame::skinDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  skillFrame::skinDataTable::CreateInstance() {
    return (gcnew skillFrame::skinDataTable());
}

inline ::System::Void skillFrame::skinDataTable::InitVars() {
    this->columnname = __super::Columns[L"name"];
    this->columnskin_table_Id = __super::Columns[L"skin_table_Id"];
}

inline ::System::Void skillFrame::skinDataTable::InitClass() {
    this->columnname = (gcnew ::System::Data::DataColumn(L"name", ::System::String::typeid, nullptr, ::System::Data::MappingType::Attribute));
    __super::Columns->Add(this->columnname);
    this->columnskin_table_Id = (gcnew ::System::Data::DataColumn(L"skin_table_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnskin_table_Id);
    this->columnname->AllowDBNull = false;
    this->columnname->Namespace = L"";
}

inline skillFrame::skinRow^  skillFrame::skinDataTable::NewskinRow() {
    return (cli::safe_cast<skillFrame::skinRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  skillFrame::skinDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew skillFrame::skinRow(builder));
}

inline ::System::Type^  skillFrame::skinDataTable::GetRowType() {
    return skillFrame::skinRow::typeid;
}

inline ::System::Void skillFrame::skinDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->skinRowChanged(this, (gcnew skillFrame::skinRowChangeEvent((cli::safe_cast<skillFrame::skinRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void skillFrame::skinDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->skinRowChanging(this, (gcnew skillFrame::skinRowChangeEvent((cli::safe_cast<skillFrame::skinRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void skillFrame::skinDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->skinRowDeleted(this, (gcnew skillFrame::skinRowChangeEvent((cli::safe_cast<skillFrame::skinRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void skillFrame::skinDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->skinRowDeleting(this, (gcnew skillFrame::skinRowChangeEvent((cli::safe_cast<skillFrame::skinRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void skillFrame::skinDataTable::RemoveskinRow(skillFrame::skinRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  skillFrame::skinDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    skillFrame^  ds = (gcnew skillFrame());
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


inline skillFrame::object_tableDataTable::object_tableDataTable() {
    this->TableName = L"object_table";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline skillFrame::object_tableDataTable::object_tableDataTable(::System::Data::DataTable^  table) {
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

inline skillFrame::object_tableDataTable::object_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, 
            ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  skillFrame::object_tableDataTable::object_table_IdColumn::get() {
    return this->columnobject_table_Id;
}

inline ::System::Data::DataColumn^  skillFrame::object_tableDataTable::skill_IdColumn::get() {
    return this->columnskill_Id;
}

inline ::System::Int32 skillFrame::object_tableDataTable::Count::get() {
    return this->Rows->Count;
}

inline skillFrame::object_tableRow^  skillFrame::object_tableDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<skillFrame::object_tableRow^  >(this->Rows[index]));
}

inline ::System::Void skillFrame::object_tableDataTable::Addobject_tableRow(skillFrame::object_tableRow^  row) {
    this->Rows->Add(row);
}

inline skillFrame::object_tableRow^  skillFrame::object_tableDataTable::Addobject_tableRow(skillFrame::skillRow^  parentskillRowByskill_object_table) {
    skillFrame::object_tableRow^  rowobject_tableRow = (cli::safe_cast<skillFrame::object_tableRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {nullptr, nullptr};
    if (parentskillRowByskill_object_table != nullptr) {
        columnValuesArray[1] = parentskillRowByskill_object_table[4];
    }
    rowobject_tableRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowobject_tableRow);
    return rowobject_tableRow;
}

inline ::System::Collections::IEnumerator^  skillFrame::object_tableDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  skillFrame::object_tableDataTable::Clone() {
    skillFrame::object_tableDataTable^  cln = (cli::safe_cast<skillFrame::object_tableDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  skillFrame::object_tableDataTable::CreateInstance() {
    return (gcnew skillFrame::object_tableDataTable());
}

inline ::System::Void skillFrame::object_tableDataTable::InitVars() {
    this->columnobject_table_Id = __super::Columns[L"object_table_Id"];
    this->columnskill_Id = __super::Columns[L"skill_Id"];
}

inline ::System::Void skillFrame::object_tableDataTable::InitClass() {
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

inline skillFrame::object_tableRow^  skillFrame::object_tableDataTable::Newobject_tableRow() {
    return (cli::safe_cast<skillFrame::object_tableRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  skillFrame::object_tableDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew skillFrame::object_tableRow(builder));
}

inline ::System::Type^  skillFrame::object_tableDataTable::GetRowType() {
    return skillFrame::object_tableRow::typeid;
}

inline ::System::Void skillFrame::object_tableDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->object_tableRowChanged(this, (gcnew skillFrame::object_tableRowChangeEvent((cli::safe_cast<skillFrame::object_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::object_tableDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->object_tableRowChanging(this, (gcnew skillFrame::object_tableRowChangeEvent((cli::safe_cast<skillFrame::object_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::object_tableDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->object_tableRowDeleted(this, (gcnew skillFrame::object_tableRowChangeEvent((cli::safe_cast<skillFrame::object_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::object_tableDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->object_tableRowDeleting(this, (gcnew skillFrame::object_tableRowChangeEvent((cli::safe_cast<skillFrame::object_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::object_tableDataTable::Removeobject_tableRow(skillFrame::object_tableRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  skillFrame::object_tableDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    skillFrame^  ds = (gcnew skillFrame());
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


inline skillFrame::objectDataTable::objectDataTable() {
    this->TableName = L"object";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline skillFrame::objectDataTable::objectDataTable(::System::Data::DataTable^  table) {
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

inline skillFrame::objectDataTable::objectDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  skillFrame::objectDataTable::idColumn::get() {
    return this->columnid;
}

inline ::System::Data::DataColumn^  skillFrame::objectDataTable::object_IdColumn::get() {
    return this->columnobject_Id;
}

inline ::System::Data::DataColumn^  skillFrame::objectDataTable::object_table_IdColumn::get() {
    return this->columnobject_table_Id;
}

inline ::System::Int32 skillFrame::objectDataTable::Count::get() {
    return this->Rows->Count;
}

inline skillFrame::objectRow^  skillFrame::objectDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<skillFrame::objectRow^  >(this->Rows[index]));
}

inline ::System::Void skillFrame::objectDataTable::AddobjectRow(skillFrame::objectRow^  row) {
    this->Rows->Add(row);
}

inline skillFrame::objectRow^  skillFrame::objectDataTable::AddobjectRow(System::Int32 id, skillFrame::object_tableRow^  parentobject_tableRowByobject_table_object) {
    skillFrame::objectRow^  rowobjectRow = (cli::safe_cast<skillFrame::objectRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(3) {id, nullptr, nullptr};
    if (parentobject_tableRowByobject_table_object != nullptr) {
        columnValuesArray[2] = parentobject_tableRowByobject_table_object[0];
    }
    rowobjectRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowobjectRow);
    return rowobjectRow;
}

inline ::System::Collections::IEnumerator^  skillFrame::objectDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  skillFrame::objectDataTable::Clone() {
    skillFrame::objectDataTable^  cln = (cli::safe_cast<skillFrame::objectDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  skillFrame::objectDataTable::CreateInstance() {
    return (gcnew skillFrame::objectDataTable());
}

inline ::System::Void skillFrame::objectDataTable::InitVars() {
    this->columnid = __super::Columns[L"id"];
    this->columnobject_Id = __super::Columns[L"object_Id"];
    this->columnobject_table_Id = __super::Columns[L"object_table_Id"];
}

inline ::System::Void skillFrame::objectDataTable::InitClass() {
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

inline skillFrame::objectRow^  skillFrame::objectDataTable::NewobjectRow() {
    return (cli::safe_cast<skillFrame::objectRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  skillFrame::objectDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew skillFrame::objectRow(builder));
}

inline ::System::Type^  skillFrame::objectDataTable::GetRowType() {
    return skillFrame::objectRow::typeid;
}

inline ::System::Void skillFrame::objectDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->objectRowChanged(this, (gcnew skillFrame::objectRowChangeEvent((cli::safe_cast<skillFrame::objectRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::objectDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->objectRowChanging(this, (gcnew skillFrame::objectRowChangeEvent((cli::safe_cast<skillFrame::objectRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::objectDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->objectRowDeleted(this, (gcnew skillFrame::objectRowChangeEvent((cli::safe_cast<skillFrame::objectRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::objectDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->objectRowDeleting(this, (gcnew skillFrame::objectRowChangeEvent((cli::safe_cast<skillFrame::objectRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::objectDataTable::RemoveobjectRow(skillFrame::objectRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  skillFrame::objectDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    skillFrame^  ds = (gcnew skillFrame());
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


inline skillFrame::skill_tableDataTable::skill_tableDataTable() {
    this->TableName = L"skill_table";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline skillFrame::skill_tableDataTable::skill_tableDataTable(::System::Data::DataTable^  table) {
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

inline skillFrame::skill_tableDataTable::skill_tableDataTable(::System::Runtime::Serialization::SerializationInfo^  info, 
            ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  skillFrame::skill_tableDataTable::skill_table_IdColumn::get() {
    return this->columnskill_table_Id;
}

inline ::System::Data::DataColumn^  skillFrame::skill_tableDataTable::player_info_IdColumn::get() {
    return this->columnplayer_info_Id;
}

inline ::System::Int32 skillFrame::skill_tableDataTable::Count::get() {
    return this->Rows->Count;
}

inline skillFrame::skill_tableRow^  skillFrame::skill_tableDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<skillFrame::skill_tableRow^  >(this->Rows[index]));
}

inline ::System::Void skillFrame::skill_tableDataTable::Addskill_tableRow(skillFrame::skill_tableRow^  row) {
    this->Rows->Add(row);
}

inline skillFrame::skill_tableRow^  skillFrame::skill_tableDataTable::Addskill_tableRow(skillFrame::player_infoRow^  parentplayer_infoRowByplayer_info_skill_table) {
    skillFrame::skill_tableRow^  rowskill_tableRow = (cli::safe_cast<skillFrame::skill_tableRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {nullptr, nullptr};
    if (parentplayer_infoRowByplayer_info_skill_table != nullptr) {
        columnValuesArray[1] = parentplayer_infoRowByplayer_info_skill_table[0];
    }
    rowskill_tableRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowskill_tableRow);
    return rowskill_tableRow;
}

inline ::System::Collections::IEnumerator^  skillFrame::skill_tableDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  skillFrame::skill_tableDataTable::Clone() {
    skillFrame::skill_tableDataTable^  cln = (cli::safe_cast<skillFrame::skill_tableDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  skillFrame::skill_tableDataTable::CreateInstance() {
    return (gcnew skillFrame::skill_tableDataTable());
}

inline ::System::Void skillFrame::skill_tableDataTable::InitVars() {
    this->columnskill_table_Id = __super::Columns[L"skill_table_Id"];
    this->columnplayer_info_Id = __super::Columns[L"player_info_Id"];
}

inline ::System::Void skillFrame::skill_tableDataTable::InitClass() {
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

inline skillFrame::skill_tableRow^  skillFrame::skill_tableDataTable::Newskill_tableRow() {
    return (cli::safe_cast<skillFrame::skill_tableRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  skillFrame::skill_tableDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew skillFrame::skill_tableRow(builder));
}

inline ::System::Type^  skillFrame::skill_tableDataTable::GetRowType() {
    return skillFrame::skill_tableRow::typeid;
}

inline ::System::Void skillFrame::skill_tableDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->skill_tableRowChanged(this, (gcnew skillFrame::skill_tableRowChangeEvent((cli::safe_cast<skillFrame::skill_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::skill_tableDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->skill_tableRowChanging(this, (gcnew skillFrame::skill_tableRowChangeEvent((cli::safe_cast<skillFrame::skill_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::skill_tableDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->skill_tableRowDeleted(this, (gcnew skillFrame::skill_tableRowChangeEvent((cli::safe_cast<skillFrame::skill_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::skill_tableDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->skill_tableRowDeleting(this, (gcnew skillFrame::skill_tableRowChangeEvent((cli::safe_cast<skillFrame::skill_tableRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::skill_tableDataTable::Removeskill_tableRow(skillFrame::skill_tableRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  skillFrame::skill_tableDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    skillFrame^  ds = (gcnew skillFrame());
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


inline skillFrame::skillDataTable::skillDataTable() {
    this->TableName = L"skill";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline skillFrame::skillDataTable::skillDataTable(::System::Data::DataTable^  table) {
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

inline skillFrame::skillDataTable::skillDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  skillFrame::skillDataTable::ekaColumn::get() {
    return this->columneka;
}

inline ::System::Data::DataColumn^  skillFrame::skillDataTable::asColumn::get() {
    return this->columnas;
}

inline ::System::Data::DataColumn^  skillFrame::skillDataTable::ssseColumn::get() {
    return this->columnssse;
}

inline ::System::Data::DataColumn^  skillFrame::skillDataTable::savableColumn::get() {
    return this->columnsavable;
}

inline ::System::Data::DataColumn^  skillFrame::skillDataTable::skill_IdColumn::get() {
    return this->columnskill_Id;
}

inline ::System::Data::DataColumn^  skillFrame::skillDataTable::skill_table_IdColumn::get() {
    return this->columnskill_table_Id;
}

inline ::System::Int32 skillFrame::skillDataTable::Count::get() {
    return this->Rows->Count;
}

inline skillFrame::skillRow^  skillFrame::skillDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<skillFrame::skillRow^  >(this->Rows[index]));
}

inline ::System::Void skillFrame::skillDataTable::AddskillRow(skillFrame::skillRow^  row) {
    this->Rows->Add(row);
}

inline skillFrame::skillRow^  skillFrame::skillDataTable::AddskillRow(System::String^  eka, System::String^  as, System::String^  ssse, 
            System::Boolean savable, skillFrame::skill_tableRow^  parentskill_tableRowByskill_table_skill) {
    skillFrame::skillRow^  rowskillRow = (cli::safe_cast<skillFrame::skillRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(6) {eka, as, ssse, savable, 
        nullptr, nullptr};
    if (parentskill_tableRowByskill_table_skill != nullptr) {
        columnValuesArray[5] = parentskill_tableRowByskill_table_skill[0];
    }
    rowskillRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowskillRow);
    return rowskillRow;
}

inline ::System::Collections::IEnumerator^  skillFrame::skillDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  skillFrame::skillDataTable::Clone() {
    skillFrame::skillDataTable^  cln = (cli::safe_cast<skillFrame::skillDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  skillFrame::skillDataTable::CreateInstance() {
    return (gcnew skillFrame::skillDataTable());
}

inline ::System::Void skillFrame::skillDataTable::InitVars() {
    this->columneka = __super::Columns[L"eka"];
    this->columnas = __super::Columns[L"as"];
    this->columnssse = __super::Columns[L"ssse"];
    this->columnsavable = __super::Columns[L"savable"];
    this->columnskill_Id = __super::Columns[L"skill_Id"];
    this->columnskill_table_Id = __super::Columns[L"skill_table_Id"];
}

inline ::System::Void skillFrame::skillDataTable::InitClass() {
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

inline skillFrame::skillRow^  skillFrame::skillDataTable::NewskillRow() {
    return (cli::safe_cast<skillFrame::skillRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  skillFrame::skillDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew skillFrame::skillRow(builder));
}

inline ::System::Type^  skillFrame::skillDataTable::GetRowType() {
    return skillFrame::skillRow::typeid;
}

inline ::System::Void skillFrame::skillDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->skillRowChanged(this, (gcnew skillFrame::skillRowChangeEvent((cli::safe_cast<skillFrame::skillRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::skillDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->skillRowChanging(this, (gcnew skillFrame::skillRowChangeEvent((cli::safe_cast<skillFrame::skillRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::skillDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->skillRowDeleted(this, (gcnew skillFrame::skillRowChangeEvent((cli::safe_cast<skillFrame::skillRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::skillDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->skillRowDeleting(this, (gcnew skillFrame::skillRowChangeEvent((cli::safe_cast<skillFrame::skillRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::skillDataTable::RemoveskillRow(skillFrame::skillRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  skillFrame::skillDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    skillFrame^  ds = (gcnew skillFrame());
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


inline skillFrame::player_infoDataTable::player_infoDataTable() {
    this->TableName = L"player_info";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline skillFrame::player_infoDataTable::player_infoDataTable(::System::Data::DataTable^  table) {
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

inline skillFrame::player_infoDataTable::player_infoDataTable(::System::Runtime::Serialization::SerializationInfo^  info, 
            ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  skillFrame::player_infoDataTable::player_info_IdColumn::get() {
    return this->columnplayer_info_Id;
}

inline ::System::Int32 skillFrame::player_infoDataTable::Count::get() {
    return this->Rows->Count;
}

inline skillFrame::player_infoRow^  skillFrame::player_infoDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<skillFrame::player_infoRow^  >(this->Rows[index]));
}

inline ::System::Void skillFrame::player_infoDataTable::Addplayer_infoRow(skillFrame::player_infoRow^  row) {
    this->Rows->Add(row);
}

inline skillFrame::player_infoRow^  skillFrame::player_infoDataTable::Addplayer_infoRow() {
    skillFrame::player_infoRow^  rowplayer_infoRow = (cli::safe_cast<skillFrame::player_infoRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(1) {nullptr};
    rowplayer_infoRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowplayer_infoRow);
    return rowplayer_infoRow;
}

inline ::System::Collections::IEnumerator^  skillFrame::player_infoDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  skillFrame::player_infoDataTable::Clone() {
    skillFrame::player_infoDataTable^  cln = (cli::safe_cast<skillFrame::player_infoDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  skillFrame::player_infoDataTable::CreateInstance() {
    return (gcnew skillFrame::player_infoDataTable());
}

inline ::System::Void skillFrame::player_infoDataTable::InitVars() {
    this->columnplayer_info_Id = __super::Columns[L"player_info_Id"];
}

inline ::System::Void skillFrame::player_infoDataTable::InitClass() {
    this->columnplayer_info_Id = (gcnew ::System::Data::DataColumn(L"player_info_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnplayer_info_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnplayer_info_Id}, 
            true)));
    this->columnplayer_info_Id->AutoIncrement = true;
    this->columnplayer_info_Id->AllowDBNull = false;
    this->columnplayer_info_Id->Unique = true;
}

inline skillFrame::player_infoRow^  skillFrame::player_infoDataTable::Newplayer_infoRow() {
    return (cli::safe_cast<skillFrame::player_infoRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  skillFrame::player_infoDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew skillFrame::player_infoRow(builder));
}

inline ::System::Type^  skillFrame::player_infoDataTable::GetRowType() {
    return skillFrame::player_infoRow::typeid;
}

inline ::System::Void skillFrame::player_infoDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->player_infoRowChanged(this, (gcnew skillFrame::player_infoRowChangeEvent((cli::safe_cast<skillFrame::player_infoRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::player_infoDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->player_infoRowChanging(this, (gcnew skillFrame::player_infoRowChangeEvent((cli::safe_cast<skillFrame::player_infoRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::player_infoDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->player_infoRowDeleted(this, (gcnew skillFrame::player_infoRowChangeEvent((cli::safe_cast<skillFrame::player_infoRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::player_infoDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->player_infoRowDeleting(this, (gcnew skillFrame::player_infoRowChangeEvent((cli::safe_cast<skillFrame::player_infoRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void skillFrame::player_infoDataTable::Removeplayer_infoRow(skillFrame::player_infoRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  skillFrame::player_infoDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    skillFrame^  ds = (gcnew skillFrame());
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


inline skillFrame::rectRow::rectRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tablerect = (cli::safe_cast<skillFrame::rectDataTable^  >(this->Table));
}

inline System::Single skillFrame::rectRow::t::get() {
    try {
        return (cli::safe_cast<::System::Single >(this[this->tablerect->tColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“rect”中列“t”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::rectRow::t::set(System::Single value) {
    this[this->tablerect->tColumn] = value;
}

inline System::Single skillFrame::rectRow::l::get() {
    try {
        return (cli::safe_cast<::System::Single >(this[this->tablerect->lColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“rect”中列“l”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::rectRow::l::set(System::Single value) {
    this[this->tablerect->lColumn] = value;
}

inline System::Single skillFrame::rectRow::b::get() {
    try {
        return (cli::safe_cast<::System::Single >(this[this->tablerect->bColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“rect”中列“b”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::rectRow::b::set(System::Single value) {
    this[this->tablerect->bColumn] = value;
}

inline System::Single skillFrame::rectRow::r::get() {
    try {
        return (cli::safe_cast<::System::Single >(this[this->tablerect->rColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“rect”中列“r”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::rectRow::r::set(System::Single value) {
    this[this->tablerect->rColumn] = value;
}

inline System::Int32 skillFrame::rectRow::box_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tablerect->box_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“rect”中列“box_Id”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::rectRow::box_Id::set(System::Int32 value) {
    this[this->tablerect->box_IdColumn] = value;
}

inline skillFrame::boxRow^  skillFrame::rectRow::boxRow::get() {
    return (cli::safe_cast<skillFrame::boxRow^  >(this->GetParentRow(this->Table->ParentRelations[L"box_rect"])));
}
inline System::Void skillFrame::rectRow::boxRow::set(skillFrame::boxRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"box_rect"]);
}

inline ::System::Boolean skillFrame::rectRow::IstNull() {
    return this->IsNull(this->tablerect->tColumn);
}

inline ::System::Void skillFrame::rectRow::SettNull() {
    this[this->tablerect->tColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean skillFrame::rectRow::IslNull() {
    return this->IsNull(this->tablerect->lColumn);
}

inline ::System::Void skillFrame::rectRow::SetlNull() {
    this[this->tablerect->lColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean skillFrame::rectRow::IsbNull() {
    return this->IsNull(this->tablerect->bColumn);
}

inline ::System::Void skillFrame::rectRow::SetbNull() {
    this[this->tablerect->bColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean skillFrame::rectRow::IsrNull() {
    return this->IsNull(this->tablerect->rColumn);
}

inline ::System::Void skillFrame::rectRow::SetrNull() {
    this[this->tablerect->rColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean skillFrame::rectRow::Isbox_IdNull() {
    return this->IsNull(this->tablerect->box_IdColumn);
}

inline ::System::Void skillFrame::rectRow::Setbox_IdNull() {
    this[this->tablerect->box_IdColumn] = ::System::Convert::DBNull;
}


inline skillFrame::pointRow::pointRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tablepoint = (cli::safe_cast<skillFrame::pointDataTable^  >(this->Table));
}

inline System::Single skillFrame::pointRow::x::get() {
    try {
        return (cli::safe_cast<::System::Single >(this[this->tablepoint->xColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“point”中列“x”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::pointRow::x::set(System::Single value) {
    this[this->tablepoint->xColumn] = value;
}

inline System::Single skillFrame::pointRow::y::get() {
    try {
        return (cli::safe_cast<::System::Single >(this[this->tablepoint->yColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“point”中列“y”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::pointRow::y::set(System::Single value) {
    this[this->tablepoint->yColumn] = value;
}

inline System::Int32 skillFrame::pointRow::frame_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tablepoint->frame_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“point”中列“frame_Id”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::pointRow::frame_Id::set(System::Int32 value) {
    this[this->tablepoint->frame_IdColumn] = value;
}

inline skillFrame::frameRow^  skillFrame::pointRow::frameRow::get() {
    return (cli::safe_cast<skillFrame::frameRow^  >(this->GetParentRow(this->Table->ParentRelations[L"frame_point"])));
}
inline System::Void skillFrame::pointRow::frameRow::set(skillFrame::frameRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"frame_point"]);
}

inline ::System::Boolean skillFrame::pointRow::IsxNull() {
    return this->IsNull(this->tablepoint->xColumn);
}

inline ::System::Void skillFrame::pointRow::SetxNull() {
    this[this->tablepoint->xColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean skillFrame::pointRow::IsyNull() {
    return this->IsNull(this->tablepoint->yColumn);
}

inline ::System::Void skillFrame::pointRow::SetyNull() {
    this[this->tablepoint->yColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean skillFrame::pointRow::Isframe_IdNull() {
    return this->IsNull(this->tablepoint->frame_IdColumn);
}

inline ::System::Void skillFrame::pointRow::Setframe_IdNull() {
    this[this->tablepoint->frame_IdColumn] = ::System::Convert::DBNull;
}


inline skillFrame::box_tableRow::box_tableRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tablebox_table = (cli::safe_cast<skillFrame::box_tableDataTable^  >(this->Table));
}

inline System::Int32 skillFrame::box_tableRow::box_table_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tablebox_table->box_table_IdColumn]));
}
inline System::Void skillFrame::box_tableRow::box_table_Id::set(System::Int32 value) {
    this[this->tablebox_table->box_table_IdColumn] = value;
}

inline System::Int32 skillFrame::box_tableRow::frame_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tablebox_table->frame_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“box_table”中列“frame_Id”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::box_tableRow::frame_Id::set(System::Int32 value) {
    this[this->tablebox_table->frame_IdColumn] = value;
}

inline skillFrame::frameRow^  skillFrame::box_tableRow::frameRow::get() {
    return (cli::safe_cast<skillFrame::frameRow^  >(this->GetParentRow(this->Table->ParentRelations[L"frame_box_table"])));
}
inline System::Void skillFrame::box_tableRow::frameRow::set(skillFrame::frameRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"frame_box_table"]);
}

inline ::System::Boolean skillFrame::box_tableRow::Isframe_IdNull() {
    return this->IsNull(this->tablebox_table->frame_IdColumn);
}

inline ::System::Void skillFrame::box_tableRow::Setframe_IdNull() {
    this[this->tablebox_table->frame_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< skillFrame::boxRow^  >^  skillFrame::box_tableRow::GetboxRows() {
    if (this->Table->ChildRelations[L"box_table_box"] == nullptr) {
        return gcnew cli::array< skillFrame::boxRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< skillFrame::boxRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"box_table_box"])));
    }
}


inline skillFrame::boxRow::boxRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tablebox = (cli::safe_cast<skillFrame::boxDataTable^  >(this->Table));
}

inline System::Int32 skillFrame::boxRow::type::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tablebox->typeColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“box”中列“type”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::boxRow::type::set(System::Int32 value) {
    this[this->tablebox->typeColumn] = value;
}

inline System::Int32 skillFrame::boxRow::box_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tablebox->box_IdColumn]));
}
inline System::Void skillFrame::boxRow::box_Id::set(System::Int32 value) {
    this[this->tablebox->box_IdColumn] = value;
}

inline System::Int32 skillFrame::boxRow::box_table_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tablebox->box_table_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“box”中列“box_table_Id”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::boxRow::box_table_Id::set(System::Int32 value) {
    this[this->tablebox->box_table_IdColumn] = value;
}

inline skillFrame::box_tableRow^  skillFrame::boxRow::box_tableRow::get() {
    return (cli::safe_cast<skillFrame::box_tableRow^  >(this->GetParentRow(this->Table->ParentRelations[L"box_table_box"])));
}
inline System::Void skillFrame::boxRow::box_tableRow::set(skillFrame::box_tableRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"box_table_box"]);
}

inline ::System::Boolean skillFrame::boxRow::IstypeNull() {
    return this->IsNull(this->tablebox->typeColumn);
}

inline ::System::Void skillFrame::boxRow::SettypeNull() {
    this[this->tablebox->typeColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean skillFrame::boxRow::Isbox_table_IdNull() {
    return this->IsNull(this->tablebox->box_table_IdColumn);
}

inline ::System::Void skillFrame::boxRow::Setbox_table_IdNull() {
    this[this->tablebox->box_table_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< skillFrame::rectRow^  >^  skillFrame::boxRow::GetrectRows() {
    if (this->Table->ChildRelations[L"box_rect"] == nullptr) {
        return gcnew cli::array< skillFrame::rectRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< skillFrame::rectRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"box_rect"])));
    }
}


inline skillFrame::frame_tableRow::frame_tableRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableframe_table = (cli::safe_cast<skillFrame::frame_tableDataTable^  >(this->Table));
}

inline System::Int32 skillFrame::frame_tableRow::frame_table_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableframe_table->frame_table_IdColumn]));
}
inline System::Void skillFrame::frame_tableRow::frame_table_Id::set(System::Int32 value) {
    this[this->tableframe_table->frame_table_IdColumn] = value;
}

inline System::Int32 skillFrame::frame_tableRow::object_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableframe_table->object_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“frame_table”中列“object_Id”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::frame_tableRow::object_Id::set(System::Int32 value) {
    this[this->tableframe_table->object_IdColumn] = value;
}

inline skillFrame::objectRow^  skillFrame::frame_tableRow::objectRow::get() {
    return (cli::safe_cast<skillFrame::objectRow^  >(this->GetParentRow(this->Table->ParentRelations[L"object_frame_table"])));
}
inline System::Void skillFrame::frame_tableRow::objectRow::set(skillFrame::objectRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"object_frame_table"]);
}

inline ::System::Boolean skillFrame::frame_tableRow::Isobject_IdNull() {
    return this->IsNull(this->tableframe_table->object_IdColumn);
}

inline ::System::Void skillFrame::frame_tableRow::Setobject_IdNull() {
    this[this->tableframe_table->object_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< skillFrame::frameRow^  >^  skillFrame::frame_tableRow::GetframeRows() {
    if (this->Table->ChildRelations[L"frame_table_frame"] == nullptr) {
        return gcnew cli::array< skillFrame::frameRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< skillFrame::frameRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"frame_table_frame"])));
    }
}


inline skillFrame::frameRow::frameRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableframe = (cli::safe_cast<skillFrame::frameDataTable^  >(this->Table));
}

inline System::Int32 skillFrame::frameRow::id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableframe->idColumn]));
}
inline System::Void skillFrame::frameRow::id::set(System::Int32 value) {
    this[this->tableframe->idColumn] = value;
}

inline System::Int32 skillFrame::frameRow::frame_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableframe->frame_IdColumn]));
}
inline System::Void skillFrame::frameRow::frame_Id::set(System::Int32 value) {
    this[this->tableframe->frame_IdColumn] = value;
}

inline System::Int32 skillFrame::frameRow::frame_table_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableframe->frame_table_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“frame”中列“frame_table_Id”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::frameRow::frame_table_Id::set(System::Int32 value) {
    this[this->tableframe->frame_table_IdColumn] = value;
}

inline skillFrame::frame_tableRow^  skillFrame::frameRow::frame_tableRow::get() {
    return (cli::safe_cast<skillFrame::frame_tableRow^  >(this->GetParentRow(this->Table->ParentRelations[L"frame_table_frame"])));
}
inline System::Void skillFrame::frameRow::frame_tableRow::set(skillFrame::frame_tableRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"frame_table_frame"]);
}

inline ::System::Boolean skillFrame::frameRow::Isframe_table_IdNull() {
    return this->IsNull(this->tableframe->frame_table_IdColumn);
}

inline ::System::Void skillFrame::frameRow::Setframe_table_IdNull() {
    this[this->tableframe->frame_table_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< skillFrame::pointRow^  >^  skillFrame::frameRow::GetpointRows() {
    if (this->Table->ChildRelations[L"frame_point"] == nullptr) {
        return gcnew cli::array< skillFrame::pointRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< skillFrame::pointRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"frame_point"])));
    }
}

inline cli::array< skillFrame::box_tableRow^  >^  skillFrame::frameRow::Getbox_tableRows() {
    if (this->Table->ChildRelations[L"frame_box_table"] == nullptr) {
        return gcnew cli::array< skillFrame::box_tableRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< skillFrame::box_tableRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"frame_box_table"])));
    }
}


inline skillFrame::skin_tableRow::skin_tableRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableskin_table = (cli::safe_cast<skillFrame::skin_tableDataTable^  >(this->Table));
}

inline System::Int32 skillFrame::skin_tableRow::skin_table_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableskin_table->skin_table_IdColumn]));
}
inline System::Void skillFrame::skin_tableRow::skin_table_Id::set(System::Int32 value) {
    this[this->tableskin_table->skin_table_IdColumn] = value;
}

inline System::Int32 skillFrame::skin_tableRow::player_info_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableskin_table->player_info_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“skin_table”中列“player_info_Id”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::skin_tableRow::player_info_Id::set(System::Int32 value) {
    this[this->tableskin_table->player_info_IdColumn] = value;
}

inline skillFrame::player_infoRow^  skillFrame::skin_tableRow::player_infoRow::get() {
    return (cli::safe_cast<skillFrame::player_infoRow^  >(this->GetParentRow(this->Table->ParentRelations[L"player_info_skin_table"])));
}
inline System::Void skillFrame::skin_tableRow::player_infoRow::set(skillFrame::player_infoRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"player_info_skin_table"]);
}

inline ::System::Boolean skillFrame::skin_tableRow::Isplayer_info_IdNull() {
    return this->IsNull(this->tableskin_table->player_info_IdColumn);
}

inline ::System::Void skillFrame::skin_tableRow::Setplayer_info_IdNull() {
    this[this->tableskin_table->player_info_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< skillFrame::skinRow^  >^  skillFrame::skin_tableRow::GetskinRows() {
    if (this->Table->ChildRelations[L"skin_table_skin"] == nullptr) {
        return gcnew cli::array< skillFrame::skinRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< skillFrame::skinRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"skin_table_skin"])));
    }
}


inline skillFrame::skinRow::skinRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableskin = (cli::safe_cast<skillFrame::skinDataTable^  >(this->Table));
}

inline System::String^  skillFrame::skinRow::name::get() {
    return (cli::safe_cast<::System::String^  >(this[this->tableskin->nameColumn]));
}
inline System::Void skillFrame::skinRow::name::set(System::String^  value) {
    this[this->tableskin->nameColumn] = value;
}

inline System::Int32 skillFrame::skinRow::skin_table_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableskin->skin_table_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“skin”中列“skin_table_Id”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::skinRow::skin_table_Id::set(System::Int32 value) {
    this[this->tableskin->skin_table_IdColumn] = value;
}

inline skillFrame::skin_tableRow^  skillFrame::skinRow::skin_tableRow::get() {
    return (cli::safe_cast<skillFrame::skin_tableRow^  >(this->GetParentRow(this->Table->ParentRelations[L"skin_table_skin"])));
}
inline System::Void skillFrame::skinRow::skin_tableRow::set(skillFrame::skin_tableRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"skin_table_skin"]);
}

inline ::System::Boolean skillFrame::skinRow::Isskin_table_IdNull() {
    return this->IsNull(this->tableskin->skin_table_IdColumn);
}

inline ::System::Void skillFrame::skinRow::Setskin_table_IdNull() {
    this[this->tableskin->skin_table_IdColumn] = ::System::Convert::DBNull;
}


inline skillFrame::object_tableRow::object_tableRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableobject_table = (cli::safe_cast<skillFrame::object_tableDataTable^  >(this->Table));
}

inline System::Int32 skillFrame::object_tableRow::object_table_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableobject_table->object_table_IdColumn]));
}
inline System::Void skillFrame::object_tableRow::object_table_Id::set(System::Int32 value) {
    this[this->tableobject_table->object_table_IdColumn] = value;
}

inline System::Int32 skillFrame::object_tableRow::skill_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableobject_table->skill_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“object_table”中列“skill_Id”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::object_tableRow::skill_Id::set(System::Int32 value) {
    this[this->tableobject_table->skill_IdColumn] = value;
}

inline skillFrame::skillRow^  skillFrame::object_tableRow::skillRow::get() {
    return (cli::safe_cast<skillFrame::skillRow^  >(this->GetParentRow(this->Table->ParentRelations[L"skill_object_table"])));
}
inline System::Void skillFrame::object_tableRow::skillRow::set(skillFrame::skillRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"skill_object_table"]);
}

inline ::System::Boolean skillFrame::object_tableRow::Isskill_IdNull() {
    return this->IsNull(this->tableobject_table->skill_IdColumn);
}

inline ::System::Void skillFrame::object_tableRow::Setskill_IdNull() {
    this[this->tableobject_table->skill_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< skillFrame::objectRow^  >^  skillFrame::object_tableRow::GetobjectRows() {
    if (this->Table->ChildRelations[L"object_table_object"] == nullptr) {
        return gcnew cli::array< skillFrame::objectRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< skillFrame::objectRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"object_table_object"])));
    }
}


inline skillFrame::objectRow::objectRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableobject = (cli::safe_cast<skillFrame::objectDataTable^  >(this->Table));
}

inline System::Int32 skillFrame::objectRow::id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableobject->idColumn]));
}
inline System::Void skillFrame::objectRow::id::set(System::Int32 value) {
    this[this->tableobject->idColumn] = value;
}

inline System::Int32 skillFrame::objectRow::object_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableobject->object_IdColumn]));
}
inline System::Void skillFrame::objectRow::object_Id::set(System::Int32 value) {
    this[this->tableobject->object_IdColumn] = value;
}

inline System::Int32 skillFrame::objectRow::object_table_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableobject->object_table_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“object”中列“object_table_Id”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::objectRow::object_table_Id::set(System::Int32 value) {
    this[this->tableobject->object_table_IdColumn] = value;
}

inline skillFrame::object_tableRow^  skillFrame::objectRow::object_tableRow::get() {
    return (cli::safe_cast<skillFrame::object_tableRow^  >(this->GetParentRow(this->Table->ParentRelations[L"object_table_object"])));
}
inline System::Void skillFrame::objectRow::object_tableRow::set(skillFrame::object_tableRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"object_table_object"]);
}

inline ::System::Boolean skillFrame::objectRow::Isobject_table_IdNull() {
    return this->IsNull(this->tableobject->object_table_IdColumn);
}

inline ::System::Void skillFrame::objectRow::Setobject_table_IdNull() {
    this[this->tableobject->object_table_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< skillFrame::frame_tableRow^  >^  skillFrame::objectRow::Getframe_tableRows() {
    if (this->Table->ChildRelations[L"object_frame_table"] == nullptr) {
        return gcnew cli::array< skillFrame::frame_tableRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< skillFrame::frame_tableRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"object_frame_table"])));
    }
}


inline skillFrame::skill_tableRow::skill_tableRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableskill_table = (cli::safe_cast<skillFrame::skill_tableDataTable^  >(this->Table));
}

inline System::Int32 skillFrame::skill_tableRow::skill_table_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableskill_table->skill_table_IdColumn]));
}
inline System::Void skillFrame::skill_tableRow::skill_table_Id::set(System::Int32 value) {
    this[this->tableskill_table->skill_table_IdColumn] = value;
}

inline System::Int32 skillFrame::skill_tableRow::player_info_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableskill_table->player_info_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“skill_table”中列“player_info_Id”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::skill_tableRow::player_info_Id::set(System::Int32 value) {
    this[this->tableskill_table->player_info_IdColumn] = value;
}

inline skillFrame::player_infoRow^  skillFrame::skill_tableRow::player_infoRow::get() {
    return (cli::safe_cast<skillFrame::player_infoRow^  >(this->GetParentRow(this->Table->ParentRelations[L"player_info_skill_table"])));
}
inline System::Void skillFrame::skill_tableRow::player_infoRow::set(skillFrame::player_infoRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"player_info_skill_table"]);
}

inline ::System::Boolean skillFrame::skill_tableRow::Isplayer_info_IdNull() {
    return this->IsNull(this->tableskill_table->player_info_IdColumn);
}

inline ::System::Void skillFrame::skill_tableRow::Setplayer_info_IdNull() {
    this[this->tableskill_table->player_info_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< skillFrame::skillRow^  >^  skillFrame::skill_tableRow::GetskillRows() {
    if (this->Table->ChildRelations[L"skill_table_skill"] == nullptr) {
        return gcnew cli::array< skillFrame::skillRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< skillFrame::skillRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"skill_table_skill"])));
    }
}


inline skillFrame::skillRow::skillRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableskill = (cli::safe_cast<skillFrame::skillDataTable^  >(this->Table));
}

inline System::String^  skillFrame::skillRow::eka::get() {
    return (cli::safe_cast<::System::String^  >(this[this->tableskill->ekaColumn]));
}
inline System::Void skillFrame::skillRow::eka::set(System::String^  value) {
    this[this->tableskill->ekaColumn] = value;
}

inline System::String^  skillFrame::skillRow::as::get() {
    try {
        return (cli::safe_cast<::System::String^  >(this[this->tableskill->asColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“skill”中列“as”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::skillRow::as::set(System::String^  value) {
    this[this->tableskill->asColumn] = value;
}

inline System::String^  skillFrame::skillRow::ssse::get() {
    try {
        return (cli::safe_cast<::System::String^  >(this[this->tableskill->ssseColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“skill”中列“ssse”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::skillRow::ssse::set(System::String^  value) {
    this[this->tableskill->ssseColumn] = value;
}

inline System::Boolean skillFrame::skillRow::savable::get() {
    try {
        return (cli::safe_cast<::System::Boolean >(this[this->tableskill->savableColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“skill”中列“savable”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::skillRow::savable::set(System::Boolean value) {
    this[this->tableskill->savableColumn] = value;
}

inline System::Int32 skillFrame::skillRow::skill_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableskill->skill_IdColumn]));
}
inline System::Void skillFrame::skillRow::skill_Id::set(System::Int32 value) {
    this[this->tableskill->skill_IdColumn] = value;
}

inline System::Int32 skillFrame::skillRow::skill_table_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableskill->skill_table_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“skill”中列“skill_table_Id”的值为 DBNull。", e));
    }
}
inline System::Void skillFrame::skillRow::skill_table_Id::set(System::Int32 value) {
    this[this->tableskill->skill_table_IdColumn] = value;
}

inline skillFrame::skill_tableRow^  skillFrame::skillRow::skill_tableRow::get() {
    return (cli::safe_cast<skillFrame::skill_tableRow^  >(this->GetParentRow(this->Table->ParentRelations[L"skill_table_skill"])));
}
inline System::Void skillFrame::skillRow::skill_tableRow::set(skillFrame::skill_tableRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"skill_table_skill"]);
}

inline ::System::Boolean skillFrame::skillRow::IsasNull() {
    return this->IsNull(this->tableskill->asColumn);
}

inline ::System::Void skillFrame::skillRow::SetasNull() {
    this[this->tableskill->asColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean skillFrame::skillRow::IsssseNull() {
    return this->IsNull(this->tableskill->ssseColumn);
}

inline ::System::Void skillFrame::skillRow::SetssseNull() {
    this[this->tableskill->ssseColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean skillFrame::skillRow::IssavableNull() {
    return this->IsNull(this->tableskill->savableColumn);
}

inline ::System::Void skillFrame::skillRow::SetsavableNull() {
    this[this->tableskill->savableColumn] = ::System::Convert::DBNull;
}

inline ::System::Boolean skillFrame::skillRow::Isskill_table_IdNull() {
    return this->IsNull(this->tableskill->skill_table_IdColumn);
}

inline ::System::Void skillFrame::skillRow::Setskill_table_IdNull() {
    this[this->tableskill->skill_table_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< skillFrame::object_tableRow^  >^  skillFrame::skillRow::Getobject_tableRows() {
    if (this->Table->ChildRelations[L"skill_object_table"] == nullptr) {
        return gcnew cli::array< skillFrame::object_tableRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< skillFrame::object_tableRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"skill_object_table"])));
    }
}


inline skillFrame::player_infoRow::player_infoRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableplayer_info = (cli::safe_cast<skillFrame::player_infoDataTable^  >(this->Table));
}

inline System::Int32 skillFrame::player_infoRow::player_info_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableplayer_info->player_info_IdColumn]));
}
inline System::Void skillFrame::player_infoRow::player_info_Id::set(System::Int32 value) {
    this[this->tableplayer_info->player_info_IdColumn] = value;
}

inline cli::array< skillFrame::skin_tableRow^  >^  skillFrame::player_infoRow::Getskin_tableRows() {
    if (this->Table->ChildRelations[L"player_info_skin_table"] == nullptr) {
        return gcnew cli::array< skillFrame::skin_tableRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< skillFrame::skin_tableRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"player_info_skin_table"])));
    }
}

inline cli::array< skillFrame::skill_tableRow^  >^  skillFrame::player_infoRow::Getskill_tableRows() {
    if (this->Table->ChildRelations[L"player_info_skill_table"] == nullptr) {
        return gcnew cli::array< skillFrame::skill_tableRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< skillFrame::skill_tableRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"player_info_skill_table"])));
    }
}


inline skillFrame::rectRowChangeEvent::rectRowChangeEvent(skillFrame::rectRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline skillFrame::rectRow^  skillFrame::rectRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction skillFrame::rectRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline skillFrame::pointRowChangeEvent::pointRowChangeEvent(skillFrame::pointRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline skillFrame::pointRow^  skillFrame::pointRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction skillFrame::pointRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline skillFrame::box_tableRowChangeEvent::box_tableRowChangeEvent(skillFrame::box_tableRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline skillFrame::box_tableRow^  skillFrame::box_tableRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction skillFrame::box_tableRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline skillFrame::boxRowChangeEvent::boxRowChangeEvent(skillFrame::boxRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline skillFrame::boxRow^  skillFrame::boxRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction skillFrame::boxRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline skillFrame::frame_tableRowChangeEvent::frame_tableRowChangeEvent(skillFrame::frame_tableRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline skillFrame::frame_tableRow^  skillFrame::frame_tableRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction skillFrame::frame_tableRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline skillFrame::frameRowChangeEvent::frameRowChangeEvent(skillFrame::frameRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline skillFrame::frameRow^  skillFrame::frameRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction skillFrame::frameRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline skillFrame::skin_tableRowChangeEvent::skin_tableRowChangeEvent(skillFrame::skin_tableRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline skillFrame::skin_tableRow^  skillFrame::skin_tableRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction skillFrame::skin_tableRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline skillFrame::skinRowChangeEvent::skinRowChangeEvent(skillFrame::skinRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline skillFrame::skinRow^  skillFrame::skinRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction skillFrame::skinRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline skillFrame::object_tableRowChangeEvent::object_tableRowChangeEvent(skillFrame::object_tableRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline skillFrame::object_tableRow^  skillFrame::object_tableRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction skillFrame::object_tableRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline skillFrame::objectRowChangeEvent::objectRowChangeEvent(skillFrame::objectRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline skillFrame::objectRow^  skillFrame::objectRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction skillFrame::objectRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline skillFrame::skill_tableRowChangeEvent::skill_tableRowChangeEvent(skillFrame::skill_tableRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline skillFrame::skill_tableRow^  skillFrame::skill_tableRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction skillFrame::skill_tableRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline skillFrame::skillRowChangeEvent::skillRowChangeEvent(skillFrame::skillRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline skillFrame::skillRow^  skillFrame::skillRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction skillFrame::skillRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline skillFrame::player_infoRowChangeEvent::player_infoRowChangeEvent(skillFrame::player_infoRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline skillFrame::player_infoRow^  skillFrame::player_infoRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction skillFrame::player_infoRowChangeEvent::Action::get() {
    return this->eventAction;
}
