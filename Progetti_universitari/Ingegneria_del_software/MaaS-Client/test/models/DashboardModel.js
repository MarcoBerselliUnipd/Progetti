import React from 'react';
import
{
  shallow
}
from 'enzyme';
import expect from 'expect'
import DashboardModel from '../../modules/model/DashboardModel'
var dash = new DashboardModel({label: "Dashboard"}, [{document: {label: "document", dsl: "document(collection:'DSL', query : '{companyId : 'matrioska'}'){show(populate:[{path:'accountId',model:'Account'}]){row(label:'email', name:'accountId_id'),row(label:'subscribedAt', name:'accountId.subscribedAt'),row(label:'databaseId', name:'databaseId')}}"}, cell: {label: "cell", dsl: "cell(label: 'NumeroAccount', type : 'string', value:{collection:'Account'})"}}, {collection: {label: "collection", dsl: "collection(name:'DSL'){index(populate:[{path:'accountId', model:'Account'}]){column(label:'Id', name:'persona.id', sortable:true, selectable:true, transformation:{}),column(label:'Età Persona', name:'età', sortable:true, selectable:true, transformation:{}),column(label:'Nome Azienda', name:'azienda.nome', sortable:true, selectable:true, transformation:{})}show(populate:['path:azienda,model:azienda']){row(label:'Nome Persona', name:'nome'),row(label:'Codice Fiscale', name:'CF'),row(label:'Età Persona', nome:'età'),row(label:'Nome Azienda', name:'azienda.nome'),row(label:'P.IVA Azienda', name:'azienda.PIVA')}}"}}]);

describe("DashboardModel", function()
{
  describe("getLabel()", function()
  {
    it("it should show the Label of the DashboardModel", function()
    {
      expect(dash.getLabel()).toBe("Dashboard");
    })
  })
  describe("DSLType()", function()
  {
    it("it should show the type of the dsl", function()
    {
      expect(dash.DSLType()).toBe("dashboard");
    })
  })
  describe("JSONbuild()", function()
  {
    it("it should show the JSON of the DashboardModel", function()
    {
      expect(dash.JSONbuild()).toEqual({ properties: { DSLType: 'dashboard', rows: [ [ { dsl: 'document(collection:\'DSL\', query : \'{companyId : \'matrioska\'}\'){show(populate:[{path:\'accountId\',model:\'Account\'}]){row(label:\'email\', name:\'accountId_id\'),row(label:\'subscribedAt\', name:\'accountId.subscribedAt\'),row(label:\'databaseId\', name:\'databaseId\')}}', label: 'document', type: 'document' }, { dsl: 'cell(label: \'NumeroAccount\', type : \'string\', value:{collection:\'Account\'})', label: 'cell', type: 'cell' } ], [ { dsl: 'collection(name:\'DSL\'){index(populate:[{path:\'accountId\', model:\'Account\'}]){column(label:\'Id\', name:\'persona.id\', sortable:true, selectable:true, transformation:{}),column(label:\'Età Persona\', name:\'età\', sortable:true, selectable:true, transformation:{}),column(label:\'Nome Azienda\', name:\'azienda.nome\', sortable:true, selectable:true, transformation:{})}show(populate:[\'path:azienda,model:azienda\']){row(label:\'Nome Persona\', name:\'nome\'),row(label:\'Codice Fiscale\', name:\'CF\'),row(label:\'Età Persona\', nome:\'età\'),row(label:\'Nome Azienda\', name:\'azienda.nome\'),row(label:\'P.IVA Azienda\', name:\'azienda.PIVA\')}}', label: 'collection', type: 'collection' } ] ] } } );
    })
  })
  describe("matrix()", function()
  {
    it("it should show the matrix of the DashboardModel", function()
    {
      expect(dash.matrix()).toEqual({ dslRows: [ undefined, undefined, [ 'document(collection:\'DSL\', query : \'{companyId : \'matrioska\'}\'){show(populate:[{path:\'accountId\',model:\'Account\'}]){row(label:\'email\', name:\'accountId_id\'),row(label:\'subscribedAt\', name:\'accountId.subscribedAt\'),row(label:\'databaseId\', name:\'databaseId\')}}', 'cell(label: \'NumeroAccount\', type : \'string\', value:{collection:\'Account\'})' ], [ 'collection(name:\'DSL\'){index(populate:[{path:\'accountId\', model:\'Account\'}]){column(label:\'Id\', name:\'persona.id\', sortable:true, selectable:true, transformation:{}),column(label:\'Età Persona\', name:\'età\', sortable:true, selectable:true, transformation:{}),column(label:\'Nome Azienda\', name:\'azienda.nome\', sortable:true, selectable:true, transformation:{})}show(populate:[\'path:azienda,model:azienda\']){row(label:\'Nome Persona\', name:\'nome\'),row(label:\'Codice Fiscale\', name:\'CF\'),row(label:\'Età Persona\', nome:\'età\'),row(label:\'Nome Azienda\', name:\'azienda.nome\'),row(label:\'P.IVA Azienda\', name:\'azienda.PIVA\')}}' ] ], labelRows: [ [ 'document', 'cell' ], [ 'collection' ] ], typeRows: [ [ 'document', 'cell' ], [ 'collection' ] ] });
    })
  })
})
